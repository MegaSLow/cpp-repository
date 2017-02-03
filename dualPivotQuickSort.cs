using System;

namespace dualPivotQuickSort
{
    public static class dualPivotQuickSort
    {
        public static int[] QuickSort(int[] a)
        {
            return QuickSort(a, 0, a.Length - 1);
        }

        public static int[] QuickSort(int[] a, int from, int to)
        {
            if (from > to)
                throw new ArgumentException("Bounds are incorrect");
            if (from < 0 || to > a.Length)
                throw new IndexOutOfRangeException();

            DualPivotQuickSort(a, from, to, 3);
            return a;
        }

        private static void Swap(int[] a, int i, int j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }

        private static void DualPivotQuickSort(int[] a, int left, int right, int div)
        {
            int len = right - left;
            if (len < 27)
            {
                for (int i = left + 1; i <= right; i++)
                    for (int j = i; j > left && a[j] < a[j - 1]; j--)
                        Swap(a, j, j - 1);
                return;
            }

            int third = len / div;

            int m1 = left + third;
            int m2 = right - third;

            if (m1 <= left)
                m1 = left + 1;

            if (m2 > right)
                m2 = right - 1;

            if (a[m1] < a[m2])
            {
                Swap(a, m1, left);
                Swap(a, m2, right);
            }
            else
            {
                Swap(a, m1, right);
                Swap(a, m2, left);
            }

            int pivot1 = a[left];
            int pivot2 = a[right];

            int less = left + 1;
            int great = right - 1;

            for (int k = less; k <= great; k++)
            {
                if (a[k] < pivot1)
                {
                    Swap(a, k, less);
                    less++;
                }
                else if (a[k] >= pivot2)
                {
                    while (k < great && a[great] >= pivot2)
                        great--;
                    Swap(a, k, great);
                    great--;
                    if (a[k] <= pivot1)
                    {
                        Swap(a, k, less);
                        less++;
                    }
                }
            }

            int dist = great - less;

            if (dist < 13)
                div++;

            Swap(a, less - 1, left);
            Swap(a, great + 1, right);

            DualPivotQuickSort(a, left, less - 2, div);
            DualPivotQuickSort(a, great + 2, right, div);

            if (pivot1 < pivot2)
            {
                DualPivotQuickSort(a, less, great, div);
            }
        }

    }
}

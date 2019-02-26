using System;
using System.Linq;

namespace Heap
{
  
    // Min heap and max heap available
    public class MaxHeap
    {
        int[] heap_array;

        public int Heap_size { get; private set; }

        public int HeapMaximum
        {
            get { return (heap_array.Length != 0) ? heap_array[0] : 0; }
        }

        public MaxHeap(int[] arr) // Initialize heap by array
        {
            heap_array = new int[arr.Length];
            Array.Copy(arr, heap_array, arr.Length);
            Heap_size = arr.Length;

            for (int i = Heap_size / 2 - 1; i >= 0; i--)
                Heapify(heap_array,i);
        }

        public MaxHeap(int size) // Initialize empty heap with suitable size
        {
            heap_array = new int[size];
            Heap_size = 0;
        }

        private int Parent(int x)
        {
            return (int)Math.Floor((double)((x + 1) / 2)) - 1;
        }

        private int LeftDescendant(int x)
        {
            return 2 * x + 1;
        }

        private int RightDescendant(int x)
        {
            return 2 * x + 2;
        }

        private void Heapify(int[] heap_arr, int x) // Recover heap property
        {
            int largestIndex;
            int l = LeftDescendant(x);
            int r = RightDescendant(x);
            if (l < Heap_size - 1 && heap_arr[l] > heap_arr[x])
                largestIndex = l;
            else
                largestIndex = x;

            if (r < Heap_size  && heap_arr[r] > heap_arr[largestIndex])
                largestIndex = r;

            if (largestIndex != x)
            {
                Swap(heap_arr,x, largestIndex);
                Heapify(heap_arr,largestIndex);
            }

        }

        public int ExtractMax()
        {
            int max = heap_array[0];
            heap_array[0] = heap_array[Heap_size - 1];
            Heap_size--;
            Heapify(heap_array,0);
            return max;
        }

        public void HeapIncreaseKey(int x, int key)
        {
            heap_array[x] = key;
            while (x > 0 && heap_array[Parent(x)] < heap_array[x])
            {
                Swap(heap_array,x, Parent(x));
                x = Parent(x);
            }
        }

        public void HeapInsert(int key)
        {
            Heap_size++;
            HeapIncreaseKey(Heap_size - 1, key);
        }


        public int[] HeapSort()
        {
            //Save heap size
            int heap_size = Heap_size;

            int[] sorted = new int[heap_array.Length];

            Array.Copy(heap_array, sorted, heap_array.Length);

            for (int i = Heap_size - 1; i >= 1; i--)
            {
                Swap(sorted, 0, i);
                Heap_size--;
                Heapify(sorted, 0);
            }

            // Restore heap size
            Heap_size = heap_size;

            return sorted;

        }

        public void Swap(int[] heap_arr,int firstIndex, int secondIndex)
        {
            int temp = heap_arr[firstIndex];
            heap_arr[firstIndex] = heap_arr[secondIndex];
            heap_arr[secondIndex] = temp;
        }
    }

    public class MinHeap
    {
        int[] heap_array;

        public int Heap_size { get; private set; }

        public int HeapMinimum
        {
            get { return (heap_array.Length != 0) ? heap_array[0] : 0; }
        }

        public MinHeap(int[] arr) // Initialize heap by array
        {
            heap_array = new int[arr.Length];
            Array.Copy(arr, heap_array, arr.Length);
            Heap_size = arr.Length;

            for (int i = Heap_size / 2 - 1; i >= 0; i--)
                Heapify(heap_array,i);
        }

        public MinHeap(int size) // Initialize empty heap with suitable size
        {
            heap_array = new int[size];
            Heap_size = 0;

        }

        private int Parent(int x)
        {
            return (int)Math.Floor((double)((x + 1) / 2)) - 1;
        }
        private int LeftDescendant(int x)
        {
            return 2 * x + 1;
        }

        private int RightDescendant(int x)
        {
            return 2 * x + 2;
        }

        public void Heapify(int[] heap_arr,int x) // Recover heap property
        {
            int lowestIndex;
            int l = LeftDescendant(x);
            int r = RightDescendant(x);
            if (l < Heap_size && heap_arr[l] < heap_arr[x])
                lowestIndex = l;
            else
                lowestIndex = x;

            if (r < Heap_size && heap_arr[r] < heap_arr[lowestIndex])
                lowestIndex = r;

            if (lowestIndex != x)
            {
                Swap(heap_arr,x, lowestIndex);
                Heapify(heap_arr,lowestIndex);
            }

        }

        public int ExtractMin()
        {
            int min = heap_array[0];
            heap_array[0] = heap_array[Heap_size - 1];
            Heap_size--;
            Heapify(heap_array,0);
            return min;
        }

        public void HeapDecreaseKey(int x, int key)
        {
            heap_array[x] = key;
            while (x > 0 && heap_array[Parent(x)] > heap_array[x])
            {
                Swap(heap_array,x, Parent(x));
                x = Parent(x);
            }
        }

        public void HeapInsert(int key)
        {
            Heap_size++;
            HeapDecreaseKey(Heap_size - 1, key);
        }

        public int[] HeapSort()
        {
            //Save heap size
            int heap_size = Heap_size;

            int[] sorted = new int[heap_array.Length];

            Array.Copy(heap_array, sorted, heap_array.Length);

            for (int i = Heap_size - 1; i >= 1; i--)
            {
                Swap(sorted, 0,i);
                Heap_size--;
                Heapify(sorted,0);
            }
            
            // Restore heap size
            Heap_size = heap_size;

           

            return sorted.Reverse().ToArray();

        }


        public void Swap(int[] heap_arr, int firstIndex, int secondIndex)
        {
            int temp = heap_arr[firstIndex];
            heap_arr[firstIndex] = heap_arr[secondIndex];
            heap_arr[secondIndex] = temp;
        }
    }
}

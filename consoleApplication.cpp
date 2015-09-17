#include <iostream>
#include <math.h>

float th(int x) {
	float y = (exp(2.0 * x) - 1.0) / (exp(2.0 * x) + 1.0);
	return y;
}
float cth(int x) {
	float y = (exp(2.0 * x) + 1.0) / (exp(2.0 * x) - 1.0);
	return y;
}
float sh(int x) {
	float y = ((exp(x) - exp(-1 * x)) / 2.0);
	return y;
}
float atan(int x) {
	float y = asin(x / sqrt(pow(x, 2) + 1));

	return y;
}

void main(void) {
	using namespace std;
	char direct = 'y';
	int n, select;
	float x, x1, y, f, p, a, l, A, t, lambda;
	const float pi = 3.14159261531;

	while (direct != 'n') {

		cout << "Enter number of variant:";
		cin >> select;

		switch (select) {

		case 1:
			printf("y = n*(n+1)/2\nEnter n:");
			scanf("%d", &n);
			printf("y=%5.1f\n", (n + 1) * n / 2.);

			printf("tg4x and y = (4* tg(x) - 4 * tg(x)^3) / (1 - 6 * tg(x)^2 + tg(x)^4)\nSet x:");
			scanf("%f", &x);
			printf("tg4x=%1.65f\n  y=%1.65f\n", tan(4.0 * x), (4 * tan(x) - 4 * pow(tan(x), 3)) / (1.0 - 6.0 * pow(tan(x), 2) + pow(tan(x), 4)));

			printf("y = a * cos^2(f) + l * cos(f)\nSet a:");
			scanf("%f", &a);
			printf("Set l:");
			scanf("%f", &l);
			printf("Set f:");
			scanf("%f", &f);
			printf("a=%1.5f l=%1.5f f=%1.5f\n y=%1.60f\n", a, l, f, a * pow(cos(f), 2) + l * cos(f));

			printf("y = a * sin(f) * cos(f) + l * sinf(f)\nCorrect values 0 <= f <= 2 * pi\nSet a:");
			scanf("%f", &a);
			printf("Set l:");
			scanf("%f", &l);
			printf("Set f:");
			scanf("%f", &f);
			if (f >= 0 && f <= 2 * pi) {

				printf("a=%1.2f l=%1.2f f=%1.2f y=%1.5f\n", a, l, f, a * sin(f) * cos(f) + l * sin(f));
			}
			else {
				printf("Entered value is not correct\n");
			}

			break;

		case 2:
			printf("y=(2*p + n)(n + 1)/2*p\nSet n:");
			scanf("%d", &n);
			printf("Set p:");
			scanf("%f", &p);
			printf("y=%1.2f\n", (2 * p + n)*(n + 1) / 2 * p);

			printf("ctg4x and y= (1 - 6*ctg(x)^2 + ctg(x)^4)/(-4 * ctg(x) + 4 * ctg(x)^3)\nSet x:");
			scanf("%f", &x);
			printf("ctg4x=%1.20f\ny=%1.20f\n", (1.0 / tan(4.0 * x)), (1.0 - 6.0 * pow((1.0 / tan(x)), 2) + pow((1.0 / tan(x)), 4)) /
				(-4.0 * (1.0 / tan(x)) + 4.0 * pow((1.0 / tan(x)), 3)));

			printf("x = (A + a)* cos(f) - a * cos( (A + a) / a * f)\ny = (A + a)* sin(f) - a * sin( (A + a) / a * f)\nCorrect values 0 <= f <= 2 * pi\nSet a:");
			scanf("%f", &a);
			printf("Set A:");
			scanf("%f", &A);
			printf("Set f:");
			scanf("%f", &f);
			if (f >= 0 && f <= 2 * pi) {

				printf("a=%f A=%f f=%f\nx=%1.5f\ny=%1.5f\n", a, A, f, (A + a)* cos(f) - a * cos((A + a) / a * f), (A + a)* sin(f) - a * sin((A + a) / a * f));
			}
			else {
				printf("Entered value is not correct\n");
			}
			break;
		case 3:

			printf("y=n*(n+1)*(2n + 1)/6\nSet n:");
			scanf("%d", &n);
			printf("y=%1.2f\n", n * (n + 1) * (2.0 * n + 1) / 6.0);

			printf("tg3x and y= (3*tg(x) - tg^3(x))/ (1 - 3 * tg^2(x))\nSet x:");
			scanf("%f", &x);
			printf("tg(3x)=%1.20f\ny=%1.20f\n", tan(3 * x), (3.0 * tan(x) - pow(tan(x), 3)) / (1.0 - 3.0 * pow(tan(x), 2)));

			printf("x = a* cos(f)*(1 + cos(f)) \ny = a* sin(f)*(1 + sin(f))\nCorrect values 0 <= f <= 2 * pi\nSet a:");
			scanf("%f", &a);
			printf("Set f:");
			scanf("%f", &f);
			if (f >= 0 && f <= 2 * pi) {

				printf("a=%f  f=%f\nx=%1.5f\ny=%1.5f\n", a, f, a* cos(f) * (1 + cos(f)), a * sin(f) * (1 + cos(f)));
			}
			else {
				printf("Entered value is not correct\n");
			}

			break;

		case 4:
			printf("y=n^2*(n+1)^2/4\nSet n:");
			scanf("%d", &n);
			printf("y=%1.2f\n", pow(n, 2) * pow(n + 1, 2) / 4.0);

			printf("ctg(3x) and y= (ctg^3(x) - 3 * ctg(x))/(3 * ctg^2(x) - 1)\nSet x:");
			scanf("%f", &x);
			printf("ctg(3x)=%1.20f\ny=%1.20f\n", (1 / tan(3 * x)), (pow((1.0 / tan(x)), 3) - 3.0 *(1.0 / tan(x))) / (3.0 * pow((1.0 / tan(x)), 2) - 1));

			printf("x = (2 * a * cos(t) / 3) + ( * cos(2*t)/3)  \ny = (2*a*sin(t)/3) - (a * sin(2*t)/3)\nCorrect values 0 <= f <= 2 * pi\nSet a:");
			scanf("%f", &a);
			printf("Set t:");
			scanf("%f", &t);
			printf("a=%f  t=%f\nx=%1.5f\ny=%1.5f\n", a, t, (2.0 * a * cos(t) / 3.0) - (a * cos(2.0 * t) / 3), (2.0 * a*sin(t) / 3.0) / (a * sin(2.0 * t) / 3.0));
			break;

		case 5:

			printf("n*(4*n^2 - 1)/3\nSet n:");
			scanf("%d", &n);
			printf("y=%1.2f\n", n *(4 * pow(n, 2) - 1) / 3.0);

			printf("sin(4x) and y= 8*cos^3(x)*sin(x) - 4 * cos(x) * sin(x) \nSet x:");
			scanf("%f", &x);
			printf("sin(4x)=%1.20f\ny=%1.20f\n", sin(4.0 * x), 8 * pow(cos(x), 3) * sin(x) - 4 * cos(x)*sin(x));

			printf("x = (A - a)* cos(f)+ lambda * a * cos((a - A)/a * f) \ny = (A - a)* sin(f)+ lambda * a * sin((a - A)/a * f)\nCorrect values 0 <= f <= 2 * pi\nSet a:");
			scanf("%f", &a);
			printf("Set A:");
			scanf("%f", &A);
			printf("Set lambda:");
			scanf("%f", &lambda);
			printf("Set f:");
			scanf("%f", &f);
			printf("a=%f A=%f lambda=%f f=%f\nx=%1.5f\ny=%1.5f\n", a, A, lambda, f, (A - a) * cos(f) + lambda * a * cos((a - A) / a * f), (A - a) * sin(f) + lambda * a * sin((a - A) / a * f));
			break;

		case 6:
			printf("n^2*(2*n^2 - 1)/5\nSet n:");
			scanf("%d", &n);
			printf("y=%1.2f\n", pow(n, 2) *(2 * pow(n, 2) - 1) / 5.0);

			printf("cos(4x) and y= 8*cos^4(x) - 8 * cos^2(x) + 1 \nSet x:");
			scanf("%f", &x);
			printf("cos(4x)=%1.20f\ny=%1.20f\n", cos(4.0 * x), 8.0 * pow(cos(x), 4) - 8.0 * pow(cos(x), 2) + 1.0);

			printf("x = 2 * a * cos(t) - a * cos(2 * t) \ny = 2 * a * sin(t) - a * sin(2 * t) \nCorrect values 0 <= f <= 2 * pi\nSet a:");
			scanf("%f", &a);
			printf("Set t:");
			scanf("%f", &t);
			printf("a=%f t=%f\nx=%1.5f\ny=%1.5f\n", a, t, 2.0 * a * cos(t) - a * cos(2.0 * t), 2.0 * a * sin(t) - a * sin(2.0 * t));

			break;
		case 7:
			printf("n*(n + 1)*(2 * n + 1)(3 * n^2 * 3 * n - 1 )/30\nSet n:");
			scanf("%d", &n);
			printf("y=%1.2f\n", n * (n + 1)*(3 * pow(n, 2) * 3 * n - 1) / 30);

			printf("cos(3x) and y= 4 * cos^3(x) - 3 * cos(x) \nSet x:");
			scanf("%f", &x);
			printf("cos(3x)=%1.20f\ny=%1.20f\n", cos(3.0 * x), 4.0 * pow(cos(x), 3) - 3.0 * cos(x));

			printf("x = 2 * a * cos(t) - a * cos(2 * t) \ny = 2 * a * sin(t) - a * sin(2 * t) \nSet a:");
			scanf("%f", &a);
			printf("Set t:");
			scanf("%f", &t);
			printf("a=%f t=%f\nx=%1.5f\ny=%1.5f\n", a, t, a*(t - sin(t)), a * (1.0 - cos(t)));

			break;

		case 8:
			printf("n^3*(n - 1)*(2 * n + 1)/30\nSet n:");
			scanf("%d", &n);
			printf("y=%1.2f\n", pow(n, 3)*(n - 1)*(2 * n + 1) / 30);

			printf("th(3x) and y=6*th^3(x) - 2*th(x) +1 \nSet x:");
			scanf("%f", &x);
			printf("th(3x)=%1.20f\ny=%1.20f\n", th(3.0 * x), 6.0 * pow(th(x), 3) - 2.0 * th(x) + 1);

			printf("x = t^3 - 3 * pi \ny = t^3 - 6*arctg(t) \nSet t:");
			scanf("%f", &t);
			printf("t=%f\nx=%1.5f\ny=%1.5f\n", t, pow(t, 3) - 3 * pi, pow(t, 3) - 6 * atan(t));

			break;

		case 9:

			printf("n*sqrt(2n + 1)/3\nSet n:");
			scanf("%d", &n);
			printf("y=%1.2f\n", n*sqrt(2 * n + 1) / 3);

			printf("cth(3x) and y=6*cth^3(x) - 2*cth(x) +1 \nSet x:");
			scanf("%f", &x);
			printf("cth(3x)=%1.20f\ny=%1.20f\n", cth(3.0 * x), 6.0 * pow(cth(x), 3) - 2.0 * cth(x) + 1);

			printf("x = t * ln(t) \ny = ln(t)/t \nSet t:");
			scanf("%f", &t);
			printf("t=%f\nx=%1.5f\ny=%1.5f\n", t, t * log(t), log(t) / t);

			break;

		case 10:

			printf("sqrt(8 + n^3 + n^2)/20\nSet n:");
			scanf("%d", &n);
			printf("y=%1.2f\n", sqrt(8 + pow(n, 3) + pow(n, 2)) / 20);

			printf("sh(3x) and y=2*sh^2(x) - sh(x) + 2 \nSet x:");
			scanf("%f", &x);
			printf("sh(3x)=%1.20f\ny=%1.20f\n", sh(3.0 * x), 2.0*pow(sh(x), 2) - sh(x) + 2.0);


			printf("x = a / cos^3(t) \ny = a * tg^3(t)\nSet a:");
			scanf("%f", &a);
			printf("Set t:");
			scanf("%f", &t);
			printf("a=%f t=%f\nx=%1.5f\ny=%1.5f\n", a, t, a / pow(cos(x), 3), a * pow(tan(x), 3));
			break;
		case 11:
			printf("\nSet n:");
			scanf("%d", &n);
			printf("y=%1.2f\n", sqrt(8 + pow(n, 3) + pow(n, 2)) / 20);
			break;
		default:
			cout << "Selected variant doesnt exist" << endl;
			break;
		}

		cout << "Enter n to exit:";
		cin >> direct;
	}
}

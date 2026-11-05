#include <stdio.h>
#include <math.h>
#include <windows.h>

void task1() {
    double A1, B1, C1, A2, B2, C2;
    double dot_product, len1, len2, cos_phi, angle_deg;

    printf(" Завдання 102:\n");

    printf("Введiть коефiцiєнти A1 B1 C1 першої прямої: ");
    scanf_s("%lf %lf %lf", &A1, &B1, &C1);

    printf("Введiть коефiцiєнти A2 B2 C2 другої прямої: ");
    scanf_s("%lf %lf %lf", &A2, &B2, &C2);

    if ((A1 == 0 && B1 == 0) || (A2 == 0 && B2 == 0)) {
        printf("Помилка: Коефiцiєнти A та B не можуть одночасно дорiвнювати нулю.\n\n");
        return;
    }

    dot_product = A1 * A2 + B1 * B2;

    if (fabs(dot_product) < 1e-9) {
        printf("Прямi перпендикулярнi (кут = 90 градусiв).\n\n");
    }
    else {
        len1 = hypot(A1, B1);
        len2 = hypot(A2, B2);

        cos_phi = fabs(dot_product) / (len1 * len2);
        if (cos_phi > 1.0) cos_phi = 1.0;

        angle_deg = acos(cos_phi) * (180.0 / 3.14159265358979323846);

        printf("Прямi не перпендикулярнi.\n");
        printf("Кут мiж ними: %.2lf градусiв.\n\n", angle_deg);
    }
}

void task2() {
    int a, b, c;
    int max, min, mid;

    printf(" Завдання 109:\n");

    printf("Введiть три рiзнi цiлi числа: ");
    scanf_s("%d %d %d", &a, &b, &c);

    if (a == b || b == c || a == c) {
        printf("Помилка: Усi числа мають бути рiзними!\n\n");
        return;
    }

    if (a > b && a > c) max = a;
    else if (b > a && b > c) max = b;
    else max = c;

    if (a < b && a < c) min = a;
    else if (b < a && b < c) min = b;
    else min = c;

    if ((a > b && a < c) || (a < b && a > c)) mid = a;
    else if ((b > a && b < c) || (b < a && b > c)) mid = b;
    else mid = c;

    printf("а) Найбiльше (Max): %d\n", max);
    printf("в) Середнє (Mid): %d\n", mid);
    printf("б) Найменше (Min): %d\n\n", min);
}

void task3() {
    int a, b, c, d;

    printf(" Завдання 15:\n");

    printf("Введiть розмiри столу a та b (де a > b): ");
    scanf_s("%d %d", &a, &b);

    printf("Введiть розмiри прямокутника c та d (де c > d): ");
    scanf_s("%d %d", &c, &d);

    if (a <= 0 || b <= 0 || c <= 0 || d <= 0) {
        printf("Помилка: Розмiри мають бути додатними числами!\n\n");
        return;
    }

    if (a <= b) {
        printf("Помилка: 'a' має бути суворо бiльшим за 'b'!\n\n");
        return;
    }

    if (c <= d) {
        printf("Помилка: 'c' має бути суворо бiльшим за 'd'!\n\n");
        return;
    }

    int count1 = (a / c) * (b / d);
    int count2 = (a / d) * (b / c);

    printf("\nРезультати:\n");
    printf("1) Двома довгими сторонами вздовж довгої сторони столу: %d прямокутникiв\n", count1);
    printf("2) Довгою стороною вздовж короткої сторони столу: %d прямокутникiв\n", count2);

    if (count1 > count2) {
        printf("Висновок: Бiльше прямокутникiв помiщається при укладаннi довгою стороною вздовж ДОВГОЇ сторони столу.\n\n");
    }
    else if (count2 > count1) {
        printf("Висновок: Бiльше прямокутникiв помiщається при укладаннi довгою стороною вздовж КОРОТКОЇ сторони столу.\n\n");
    }
    else {
        printf("Висновок: Обидва способи дають ОДНАКОВУ кiлькiсть прямокутникiв (%d).\n\n", count1);
    }
}

void calcArea(double x1, double y1, double x2, double y2, double x3, double y3, double* area) {
    *area = 0.5 * fabs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
}

void task4() {
    double ax, ay, bx, by, cx, cy;
    double px, py;
    double S_abc, S_pab, S_pbc, S_pac;

    printf(" Завдання 52:\n");

    printf("Введiть координати вершин трикутника (Ax Ay Bx By Cx Cy): ");
    scanf_s("%lf %lf %lf %lf %lf %lf", &ax, &ay, &bx, &by, &cx, &cy);

    printf("Введiть координати точки (Px Py): ");
    scanf_s("%lf %lf", &px, &py);

    calcArea(ax, ay, bx, by, cx, cy, &S_abc);
    calcArea(px, py, ax, ay, bx, by, &S_pab);
    calcArea(px, py, bx, by, cx, cy, &S_pbc);
    calcArea(px, py, ax, ay, cx, cy, &S_pac);

    if (fabs(S_abc - (S_pab + S_pbc + S_pac)) < 1e-6) {
        printf("Точка лежить ВСЕРЕДИНI (або на межi) трикутника.\n\n");
    }
    else {
        printf("Точка лежить ПОЗА трикутником.\n\n");
    }
}

double findMiddle(double x, double y, double z) {
    if ((x > y && x < z) || (x < y && x > z)) return x;
    if ((y > x && y < z) || (y < x && y > z)) return y;
    return z;
}

void task5() {
    double a1, b1, c1;
    double a2, b2, c2;
    double mid1, mid2, avg;

    printf(" Завдання 113:\n");

    printf("Введiть першу трiйку рiзних дiйсних чисел: ");
    scanf_s("%lf %lf %lf", &a1, &b1, &c1);

    printf("Введiть другу трiйку рiзних дiйсних чисел: ");
    scanf_s("%lf %lf %lf", &a2, &b2, &c2);

    if (a1 == b1 || b1 == c1 || a1 == c1 || a2 == b2 || b2 == c2 || a2 == c2) {
        printf("Помилка: Усi числа в кожнiй трiйцi мають бути рiзними!\n\n");
        return;
    }

    mid1 = findMiddle(a1, b1, c1);
    mid2 = findMiddle(a2, b2, c2);
    avg = (mid1 + mid2) / 2.0;

    printf("Середнє число 1-ї трiйки: %.2lf\n", mid1);
    printf("Середнє число 2-ї трiйки: %.2lf\n", mid2);
    printf("Середнє арифметичне середнiх чисел: %.2lf\n\n", avg);
}

void task6() {
    int n, a, sum = 0;

    printf(" Завдання 91:\n");

    printf("Введiть кiлькiсть квартир (n) та початковий номер (a): ");
    scanf_s("%d %d", &n, &a);

    if (n <= 0 || a <= 0) {
        printf("Помилка: n та a мають бути додатними числами!\n\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        sum += (a + i);
    }

    printf("Сума номерiв усiх квартир: %d\n", sum);
    if (sum % 2 == 0) {
        printf("Сума є ПАРНИМ числом.\n\n");
    }
    else {
        printf("Сума є НЕПАРНИМ числом.\n\n");
    }
}

void task7() {
    double a1, b1, c1, a2, b2, c2;
    double D, Dx, Dy, x, y;

    printf(" Завдання 105:\n");

    printf("Введiть коефiцiєнти a1 b1 c1: ");
    scanf_s("%lf %lf %lf", &a1, &b1, &c1);

    printf("Введiть коефiцiєнти a2 b2 c2: ");
    scanf_s("%lf %lf %lf", &a2, &b2, &c2);

    D = a1 * b2 - a2 * b1;
    Dx = c1 * b2 - c2 * b1;
    Dy = a1 * c2 - a2 * c1;

    if (fabs(D) > 1e-9) {
        x = Dx / D;
        y = Dy / D;
        printf("Система має єдиний розв'язок: x = %.2lf, y = %.2lf\n\n", x, y);
    }
    else {
        if (fabs(Dx) < 1e-9 && fabs(Dy) < 1e-9) {
            printf("Система має безлiч розв'язкiв.\n\n");
        }
        else {
            printf("Система не має розв'язкiв.\n\n");
        }
    }
}

void task8() {
    double a, b, c;

    printf(" Завдання 48:\n");

    printf("Введiть сторони трикутника a, b, c: ");
    scanf_s("%lf %lf %lf", &a, &b, &c);

    if (a <= 0 || b <= 0 || c <= 0 || (a + b <= c) || (a + c <= b) || (b + c <= a)) {
        printf("Помилка: Введенi сторони не утворюють трикутник!\n\n");
        return;
    }

    if (fabs(a * a + b * b - c * c) < 1e-6) {
        printf("Трикутник прямокутний. Гiпотенузою є сторона c.\n\n");
    }
    else if (fabs(a * a + c * c - b * b) < 1e-6) {
        printf("Трикутник прямокутний. Гiпотенузою є сторона b.\n\n");
    }
    else if (fabs(b * b + c * c - a * a) < 1e-6) {
        printf("Трикутник прямокутний. Гiпотенузою є сторона a.\n\n");
    }
    else {
        printf("Трикутник НЕ є прямокутним.\n\n");
    }
}

void task9() {
    int n;

    printf(" Завдання 39:\n");

    printf("Введiть кiлькiсть пелюсток n: ");
    scanf_s("%d", &n);

    if (n <= 0) {
        printf("Помилка: Кiлькiсть пелюсток має бути додатним числом!\n\n");
        return;
    }

    if (n % 2 != 0) {
        printf("Результат ворожiння: Любить\n\n");
    }
    else {
        printf("Результат ворожiння: Не любить\n\n");
    }
}

void task10() {
    double a, b, c;

    printf(" Завдання 84:\n");

    printf("Введiть сторони трикутника a, b, c: ");
    scanf_s("%lf %lf %lf", &a, &b, &c);

    if (a <= 0 || b <= 0 || c <= 0 || (a + b <= c) || (a + c <= b) || (b + c <= a)) {
        printf("Помилка: Введенi сторони не утворюють трикутник!\n\n");
        return;
    }

    if (fabs(a - b) < 1e-6 || fabs(a - c) < 1e-6 || fabs(b - c) < 1e-6) {
        printf("Трикутник Є рiвнобедреним.\n\n");
    }
    else {
        printf("Трикутник НЕ є рiвнобедреним.\n\n");
    }
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    task1();
    task2();
    task3();
    task4();
    task5();
    task6();
    task7();
    task8();
    task9();
    task10();

    return 0;
}
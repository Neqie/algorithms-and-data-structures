#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#define MAX 90000

void cout_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        if (i == 0) printf("Текущий массив: ");
        printf("%d | ", arr[i]);
    }
}

int input_arr(int arr[]) {
    int res;
    do {
        printf("Введите количество элементов в массиве");
        scanf_s("%d", &res);
    } while ((res < 1) || (res > MAX));
    if (res <= 20) {
        for (int i = 0; i < res; i++) {
            scanf_s("%d", &arr[i]);
        }
    }
    else {
        for (int i = 0; i < res; i++) {
            arr[i] = rand();
        }
    }
    return res;
}

long long linesort(int arr[], int n) {
    long long r = 0;
    for (int i = 0; i < n; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
            r += 1;
        }
        int cop = arr[i];
        arr[i] = arr[min];
        arr[min] = cop;
        r += 4;
    }
    return r;
}

long long bubblesort(int arr[], int n) {
    double cop = 0;
    long long r = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                cop = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = cop;
                r += 3;
            }
            r += 1;
        }
        r += 1;
    }
    return r;
}

int line_search(int arr[], int n, int ch) {
    int  id = -1, flag = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == ch) {
            id = i;
        }
    }
    return id;
}

int sentinel_search(int arr[], int n, int ch) {
    int last = arr[n - 1];
    arr[n - 1] = ch;
    int i = 0;
    while (arr[i] != ch)
        i++;
    arr[n - 1] = last;
    if (i == n - 1) {
        if (last != ch) return -1;
        else return n - 1;
    }
    else return i;

}

long long insertionsort(int arr[], int n) {
    double ch = 0;
    long long r = 0;
    int pos = 0;
    for (int i = 1; i < n; i++) {
        ch = arr[i];
        pos = i - 1;
        while (pos >= 0 && arr[pos] > ch) {
            arr[pos + 1] = arr[pos];
            pos -= 1;
            r += 1;
        }
        r += 1;
        arr[pos + 1] = ch;
    }
    return r;
}

int bin_search(int arr[], int n, int ch) {
    int l = 0, r = n - 1, sr = 0, flag = 1, res = -1;
    while (l < r) {
        sr = (l + r) / 2;
        if (arr[sr] == ch) { res = sr; break; }
        else if (arr[sr] < ch) l = sr + 1;
        else r = sr - 1;
    }
    if ((l == r) && (arr[l] == ch)) res = l;
    else if ((l == r) && (arr[r] == ch)) res = r;
    return res;
}

int sorted(int arr[], int n) {
    int res = 1;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            res = -1;
            break;
        }
    }
    return res;
}

void make_some_copy(int real[], int copy[], int n) {
    for (int i = 0; i < n; i++) {
        copy[i] = real[i];
    }
}

void time_count(int arr[], int arrcopy[], int n) {
    if (n == 0) printf("Сначала введите массив");
    else {
        printf("            Операций / Время(сек)\n");
        clock_t start1 = clock();
        long long lineres = linesort(arr, n);
        clock_t end1 = clock();
        make_some_copy(arrcopy, arr, n);
        printf("\nlinesort   | %lld | %f\n", lineres, (double)(end1 - start1) / CLOCKS_PER_SEC);
        clock_t start2 = clock();
        long long bubbleres = bubblesort(arr, n);
        clock_t end2 = clock();
        make_some_copy(arrcopy, arr, n);
        printf("bubblesort | %lld | %f\n", bubbleres, (double)(end2 - start2) / CLOCKS_PER_SEC);
        clock_t start3 = clock();
        long long insertres = insertionsort(arr, n);
        clock_t end3 = clock();
        make_some_copy(arrcopy, arr, n);
        printf("insertsort | %lld   | %f\n", insertres, (double)(end3 - start3) / CLOCKS_PER_SEC);
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int a[MAX], ch = 0, ans, answer = 1, size_a = 0, c = 0, copy_a[MAX], size_copya = 0;
    do {
        printf("Выберете какую функцию вы хотите вызвать:\n1 - Создать массив чисел\n2 - Линейная сортировка массива\n3 - Пузырьковая сортировка массива\n4 - Сортировка вставкой\n5 - Линейный поиск\n6 - Поиск барьером\n7 - Бинарный поиск\n8 - Вывод текущего массива\n9 - Посчитать время сортировок\n0 - Выход из программы\n");
        scanf_s("%d", &ans);
        switch (ans) {
        case 1: size_a = input_arr(a); size_copya = size_a; make_some_copy(a, copy_a, size_a); break;
        case 2: if (size_a == 0) printf("Сначала нужно ввести массив"); else printf("Количество операций = %d", linesort(a, size_a)); break;
        case 3: if (size_a == 0) printf("Сначала нужно ввести массив"); else printf("Количество операций = %d", bubblesort(a, size_a)); break;
        case 4: if (size_a == 0) printf("Сначала нужно ввести массив"); else printf("Количество операций = %d", insertionsort(a, size_a)); break;
        case 5:
            if (size_a == 0) printf("Сначала нужно ввести массив");
            else {
                printf("Введите какое число вы хотите найти");
                scanf_s("%d", &ch);
                if (line_search(a, size_a, ch) == -1) printf("Такого числа в массиве нет");
                else printf("Индекс числа в массиве = %d", line_search(a, size_a, ch));
            }
            break;
        case 6:
            if (size_a == 0) printf("Сначала нужно ввести массив");
            else {
                printf("Введите какое число вы хотите найти");
                scanf_s("%d", &ch);
                if (sentinel_search(a, size_a, ch) == -1) printf("Такого числа в массиве нет");
                else printf("Индекс числа в массиве = %d", sentinel_search(a, size_a, ch));
            }
            break;
        case 7:
            if (size_a == 0) printf("Сначала введите массив");
            else if (sorted(a, size_a) == -1) printf("Сначала отсортируйте массив");
            else {
                printf("Введите число, которое ищете");
                scanf_s("%d", &ch);
                if (bin_search(a, size_a, ch) == -1) printf("Такого числа в массиве нет");
                else printf("Индекс числа в массиве = %d", bin_search(a, size_a, ch));
            }
            break;
        case 8: if (size_a == 0) printf("Сначала нужно ввести массив"); else cout_array(a, size_a); break;
        case 9: time_count(a, copy_a, size_a); break;
        case 0: answer = 0; break;
        default: printf("Введите верные данные"); break;
        }
        if (answer != 0) {
            printf("\nЕсли Вы хотите вернуться в меню, введите 1: ");
            scanf_s("%d", &answer);
        }
    } while (answer == 1);
    return 0;
}

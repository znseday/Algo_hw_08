# Algo_hw_08

Otus-Algo, Homework 08 - Range Sum

Решить олимпиадную задачу "Сумма на отрезке"

Ссылка на задачу: http://codeforces.com/gym/100249/

Дан массив из N элементов. Нужно научиться находить сумму чисел на любом отрезке. Формат входного файла.

Первая строка входного айла содержит два целых числа:

N - число чисел в массиве (1 ≤ N ≤ 100 000),

K - количество запросов (0 ≤ K ≤ 100 000).

Следующие K строк содержат запросы вида:

A i x присвоить i-му элементу массива значение x (1 ≤ i ≤ N, 0 ≤ x ≤ 10^9)

Q L R найти сумму чисел в массиве на позициях от L до R. (1 ≤ L ≤ R ≤ N)

Изначально массиве заполнен нулями.

Формат выходного файла:

На каждый запрос вида Q L R нужно вывести единственное число - сумму на отрезке.

Пример

sum.in

5 9

A 2 2

A 3 1

A 4 2

Q 1 1

Q 2 2

Q 3 3

Q 4 4

Q 5 5

Q 1 5

sum.out

0

2

1

2

0

5

Написанную программу отправьте на проверку на сайте http://codeforces.com/gym/100249/

# VertexCover

Имплементация алгоритма для проекта по сложности вычислений

**62. Вершинное покрытие**

Известно, что для задачи вершинного покрытия существует простой алгоритм, дающий 2-приближение. 
Он состоит в том, чтобы найти максимальное паросочетание в графе и взять по вершине из каждого ребра.
Рассмотрим взвешенный вариант задачи. То есть дан граф G = (V, E), а также функция w : V → R+. 
Требуется найти множество минимального веса, покрывающее все рёбра графа, т. е. такое U ⊂ V, что для любого (u, v) ∈ E верно u ∈ U 
или v ∈ U и сумма весов вершин из U минимальна.

**Задание**

Требуется построить алгоритм дающий 2-приближение для взвешенной задачи вершинного покрытия, а также имплементировать его.
Подсказка: рассмотрите частный случай графа, в котором w(u) = c ·deg(u).
Ответ для таких графов строится просто, остается декомпозировать исходную задачу на задачи такого вида.
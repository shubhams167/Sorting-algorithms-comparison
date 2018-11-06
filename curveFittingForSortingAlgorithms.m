%Read bubble sort comparison data
result = csvread('bubbleSortResult.csv');
size = result(:, 1);
time = result(:, 2);
comparisons = result(:, 3);
figure
subplot(2, 1, 1)
plot(size, time)
title('Bubble sort: input size vs time taken')
grid on
xlabel('Input size')
ylabel('Time taken(in ms)');
subplot(2, 1, 2)
plot(size, comparisons)
title('Bubble sort: input size vs number of comparisons')
grid on
xlabel('Input size')
ylabel('Number of comparisons');

%Read insertion sort comparison data
result = csvread('insertionSortResult.csv');
size = result(:, 1);
time = result(:, 2);
comparisons = result(:, 3);
figure
subplot(2, 1, 1)
plot(size, time)
title('Insertion sort: input size vs time taken')
grid on
xlabel('Input size')
ylabel('Time taken(in ms)');
subplot(2, 1, 2)
plot(size, comparisons)
title('Insertion sort: input size vs number of comparisons')
grid on
xlabel('Input size')
ylabel('Number of comparisons');


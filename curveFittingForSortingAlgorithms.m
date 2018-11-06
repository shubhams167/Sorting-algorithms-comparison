%Read bubble sort comparison data
bubbleResult = csvread('bubbleSortResult.csv');
size = bubbleResult(:, 1);
time = bubbleResult(:, 2);
comparisons = bubbleResult(:, 3);
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


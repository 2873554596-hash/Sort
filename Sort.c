#include<sort.h>

void InsertSort(int* a, int n){
    for(i = 0; i < n - 1; i++)
    int end = i;
    int tmp = a[end + 1];
    while (end >= 0){
        if (a[end] > a[tmp]){
            a[end +1] = a[end];
            end--;
        }
        else{
            break;
        }
        a[end + 1] = tmp;
    }
}

void ShellSOrt(int* a, int n)
    int d = n;

    while(d > 1){
        d = d / 3 + 1
    }

    for(j = 0; j < d; j++){
        for(i = j ; i < n - d; i += d){
            int end = d;
            int tmp = a[end + d];
            while(end >= 0){
                if (tmp < a[end]){
                    a[end + d] = a[end];
                    end -= d;
                }
                else{
                    break;
                }
            }
            a[end + d] = tmp;
        }

    }

void SelectSort(int* a, int n){
    for(int j = 0; j <= n - 1; j++){
        int mini = j;
        for(int i = j +1; i < n; i++)
        if(a[i] < a[mini]){
            mini = i;
        }
    }
    Swap(&a[mini], &a[j]);
}

void BubbleSort(int* a, int n) {
	for (int j = 0; j < n-1; j++) {
		int flag = 0;
		for (int i = 1; i < n-j; i++) {
			if (a[i - 1] > a[i]) {
				Swap(&a[i - 1], &a[i]);
				flag = 1;
			}
		}

		// 一趟冒泡没有发生交换，则说明有序，排序完成
		if (flag == 0) {
			break;
		}
	}
}

void AdjustDowm(int* a, int n, int parent){
    child = parent * 2 + 1;
    while(child < n)A{
        if(child + 1 < n && a[child + 1] > a[child]){
            ++child;
        }
        if(a[child] > a[parent]){
            Swap(&a[parent], &a[child]);
            parent = child;
            child = parent * 2 + 1;
        }
        else{
            break;
        }
    }
}
void HeapSort(int* a, int n){
    for(int i = (n - j - 1) / 2; i >= 0; i--){
    AdjustDowm(a, n, i);
    }
    int j = 1;
    while(j < n){
        Swap(&a[0], &a[n - j]);
        AdjustDowm(a, n - j, 0);
        ++j；
    }
}

//low 是较低的下标，且会从左往右移到；high 是较高的下标，且会从右往左移到。他们被看做待划分区间
void ParttionDigHole(int* a, int low, int high){
    int pivot = a[low]；            //pivot是基准值,low、high 是待处理区间的左右下标，包含这两个位置。
    while(a[low] < a[high]){
        while(low < high && a[high] >= pivot)
            --high;
            a[low] = a[high];    //注意：这里是赋值，不是交换。
        while(low < high && a[low] <= pivot){
            ++low;
            a[high] = a[low];
        }
    }
    a[low] = pivot;
    return low;
}

int PartitionLomuto(int* a, int low, int high) {
    int pivot = a[high];
    int prev = low - 1;

    for (int cur = low; cur < high; ++cur) {
        if (a[cur] < pivot) {
            ++prev;

            if (prev != cur) {
                Swap(&a[prev], &a[cur]);
            }
        }
    }

    ++prev;
    Swap(&a[prev], &a[high]);

    return prev;
}

//left 和 right 表示当前要排序区间的左右下标
void QuickSort(int* a, int left, int right) {
	if (left >= right)
		return;

	int pivoti = ParttionDigHole(a, left, right);
	QuickSort(a, left, pivoti - 1);
	QuickSort(a, pivoti+1, right);
}

void CountSort(int* a, int n) {
	int min = a[0], max = a[0];
	for (int i = 1; i < n; ++i) {
		if (a[i] < min)
			min = a[i];

		if (a[i] > max)
			max = a[i];
	}

	int range = max - min + 1;
	printf("range:%d\n", range);
	int* count = (int*)calloc(sizeof(int) * range, sizeof(int));
	if (count == NULL) {
		perror("calloc fail");
		return;
	}

	// 统计数据个数
	for (int i = 0; i < n; ++i) {
		count[a[i] - min]++;
	}

	// 统计小于等于映射到i为的值x的个数
	for (int i = 1; i < range; ++i) {
		count[i] += count[i - 1];
	}

	int* tmp = (int*)malloc(sizeof(int)*n);
	if (count == NULL) {
		perror("malloc fail");
		return;
	}

	// 计算原数组的值排序后的位置，放到tmp数组
	for (int i = n-1; i>=0; --i) {
		tmp[count[a[i] - min] - 1] = a[i];
		count[a[i] - min]--;
	}

	for (int i = 0; i < n; ++i) {
		a[i] = tmp[i];
	}
}
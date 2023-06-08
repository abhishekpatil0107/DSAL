import java.util.Arrays;
public class HeapSort {
public static void main(String[] args) {
int[] arr = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
heapSort(arr);
System.out.println(Arrays.toString(arr));
}
public static void heapSort(int[] arr) {
// Create a max heap
buildHeap(arr);
// Iterate over the array from the end, swapping the root element with the last element
// and then heapifying the remaining elements
for (int i = arr.length - 1; i > 0; i--) {
int temp = arr[0];
arr[0] = arr[i];
arr[i] = temp;
heapify(arr, 0, i - 1);
}
}
// Builds a max heap from the given array
public static void buildHeap(int[] arr) {
for (int i = arr.length / 2 - 1; i >= 0; i--) {
heapify(arr, i, arr.length - 1);
}
}
// Heapifies the given array starting from the given index
public static void heapify(int[] arr, int index, int size) {
int largest = index;
int left = 2 * index + 1;
int right = 2 * index + 2;
if (left < size && arr[left] > arr[largest]) {
largest = left;
}
if (right < size && arr[right] > arr[largest]) {
largest = right;
}
if (largest != index) {
int temp = arr[index];
arr[index] = arr[largest];
arr[largest] = temp;
heapify(arr, largest, size);
}
}
}

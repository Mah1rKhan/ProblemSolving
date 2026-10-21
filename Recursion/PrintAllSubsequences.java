import java.util.*;

public class PrintAllSubsequences {

    public static void display(int arr[]) {
        int n = arr.length;
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    public static void generate(int arr[], int ind,
            Vector<Vector<Integer>> subsequences,
            Vector<Integer> currentSubsequence) {

        if (ind == arr.length) {
            subsequences.add(new Vector<>(currentSubsequence));
            return;
        }

        // Pick condition
        currentSubsequence.add(arr[ind]);
        generate(arr, ind + 1, subsequences, currentSubsequence);

        // Not pick condition
        currentSubsequence.remove(currentSubsequence.size() - 1);
        generate(arr, ind + 1, subsequences, currentSubsequence);
    }

    public static Vector<Vector<Integer>> generateSubsequences(int arr[]) {
        Vector<Vector<Integer>> subsequences = new Vector<>();
        Vector<Integer> currentSubsequence = new Vector<>();
        generate(arr, 0, subsequences, currentSubsequence);

        return subsequences;
    }

    public static void display(Vector<Integer> subsequence) {
        for (Integer x : subsequence) {
            System.out.print(x + " ");
        }
        System.out.println();
    }

    public static void displayAll(Vector<Vector<Integer>> subsequences) {
        for (Vector<Integer> subsequence : subsequences) {
            display(subsequence);
        }
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("How many elements are there? Enter here : ");
        int n = input.nextInt();
        int[] array = new int[n];

        System.out.print("Enter elements here : ");

        for (int i = 0; i < n; i++) {
            int ele = input.nextInt();
            array[i] = ele;
        }

        System.out.print("Array is : ");
        display(array);

        Vector<Vector<Integer>> subsequences = generateSubsequences(array);

        System.out.println("Subsequences are : ");

        displayAll(subsequences);

        input.close();

    }

}

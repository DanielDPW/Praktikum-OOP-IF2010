import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.ListIterator;
import java.util.Scanner;

public class IntegerListProcessor {
    // Gunakan function ini untuk output
    private static void printList(List<Integer> list) {
        for (int i = 0; i < list.size(); i++) {
            System.out.print(list.get(i));
            if (i < list.size() - 1) {
                System.out.print(" ");
            }
        }
        System.out.println();
    }

    // Wajib menggunakan Java Collections API untuk semua operasi pada list
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // 1. Baca N. N adalah jumlah input
        int N = sc.nextInt();

        // 2. Baca N bilangan dan simpan ke List<Integer>
        List<Integer> list = new ArrayList<Integer>();
        for (int i = 0; i < N; i++) {
            int temp = sc.nextInt();
            list.add(temp);
        }

        // 3. Hapus semua elemen genap
        list.removeIf(n -> n % 2 == 0);

        // 4. Jika panjang list sekarang ganjil, sort ascending; else sort descending
        if (list.size() % 2 == 1) {
            list.sort(Comparator.naturalOrder());
        } else {
            list.sort(Comparator.reverseOrder());
        }
    
        // 5. Untuk setiap elemen, kalikan dengan tiga
        list.replaceAll(n -> n * 3);

        // 6. Cetak elemen menggunakan method printList
        printList(list);

        sc.close();
    }
}

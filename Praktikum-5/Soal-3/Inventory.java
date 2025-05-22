import java.util.ArrayList;
import java.util.List;

/**
 * Pastikan kalian menggunakan type parameter yang benar
 */
public class Inventory {
    private List<Box<?>> boxes;

    // Constructor, inisiasi dengan list of boxes
    public Inventory(List<Box<?>> boxes) {
        this.boxes = boxes;
    }

    // Method untuk membuka semua box
    public void openAll() {
        for (Box<?> b : boxes) {
            b.open();
        }
    }

    // Method untuk menambahkan box
    public void addBox(Box<?> b) {
        boxes.add(b);
    }

    // Method untuk menghapus box
    public void removeBox(Box<?> b) {
        boxes.remove(b);
    }

    // Getter dan setter
    public List<Box<?>> getBoxes() {
        return boxes;
    }
    
    public void setBoxes(List<Box<?>> boxes) {
        this.boxes = boxes;
    }

    
    
}
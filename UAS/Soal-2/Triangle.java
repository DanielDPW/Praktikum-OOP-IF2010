public class Triangle extends Shape {
    private double base = 4.0;   // Default base
    private double height = 3.0; // Default height
    private double side1 = 3.0;  // Default sides for perimeter
    private double side2 = 4.0;
    private double side3 = 5.0;
    
    @Override
    public void draw() {
        System.out.println("Drawing a Triangle");
    }
    
    @Override
    public double calculateArea() {
        return 0.5 * base * height;
    }
    
    @Override
    public double calculatePerimeter() {
        return side1 + side2 + side3;
    }
}
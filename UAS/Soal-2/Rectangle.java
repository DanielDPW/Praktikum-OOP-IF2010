public class Rectangle extends Shape {
    private double width = 4.0;  // Default width
    private double height = 6.0; // Default height
    
    @Override
    public void draw() {
        System.out.println("Drawing a Rectangle");
    }
    
    @Override
    public double calculateArea() {
        return width * height;
    }
    
    @Override
    public double calculatePerimeter() {
        return 2 * (width + height);
    }
}
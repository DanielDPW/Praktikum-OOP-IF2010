public class Circle extends Shape {
    private double radius = 5.0; // Default radius
    
    @Override
    public void draw() {
        System.out.println("Drawing a Circle");
    }
    
    @Override
    public double calculateArea() {
        return 3.14 * radius * radius;
    }
    
    @Override
    public double calculatePerimeter() {
        return 2 * 3.14 * radius;
    }
}
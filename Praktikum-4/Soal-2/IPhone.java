public class IPhone extends Device {
    private int batteryLevel;
    
    // Set battery level to 100 on initialization
    public IPhone() {
        super("IPhone");
        this.batteryLevel = 100;
    }
    
    @Override
    // Print out "IPhone is nearby! Distance: *batteryLevel* meters away"
    // Decrease the battery level by 10
    // If the battery level is 0, print out "IPhone battery is depleted"
    // If the device is not connected, print out "IPhone is not connected"
    // If the device is connected and the battery level is greater than 0, print out "IPhone is nearby! Distance: *batteryLevel* meters away"
    public void locate() {
        if (batteryLevel <= 0) {
            System.out.println("IPhone battery is depleted");
        } else if (!connected) {
            System.out.println("IPhone is not connected");
        } else {
            System.out.println("IPhone is nearby! Distance: " + batteryLevel + " meters away");
            if (batteryLevel >= 10) {
                batteryLevel -= 10;
            } else {
                batteryLevel = 0;
            }
        }
    }
    
    @Override
    // Print out "IPhone: *LOUD BEEPING*"
    // Decrease the battery level by 20
    // If the battery level is 0, print out "IPhone battery is depleted"
    // If the device is not connected, print out "IPhone is not connected"
    // If the device is connected and the battery level is greater than 0, print out "IPhone: *LOUD BEEPING*"
    public void makeSound() {
        if (batteryLevel <= 0) {
            System.out.println("IPhone battery is depleted");
        } else if (!connected) {
            System.out.println("IPhone is not connected");
        } else {
            System.out.println("IPhone: *LOUD BEEPING*");
            if (batteryLevel >= 20) {
                batteryLevel -= 20;
            } else {
                batteryLevel = 0;
            }
        }
    }
    
    // Set the battery level to 100
    // Print out "IPhone charged to 100%"
    public void charge() {
        this.batteryLevel = 100;
        System.out.println("IPhone charged to 100%");
    }
}
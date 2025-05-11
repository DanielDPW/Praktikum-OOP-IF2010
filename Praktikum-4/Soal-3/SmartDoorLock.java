/**
 * SmartDoorLock - Kelas yang merepresentasikan kunci pintu pintar rumah
 * Kelas ini mewarisi SecurityDevice dan mengimplementasikan EnergyMonitored
 * untuk membuat perangkat keamanan dengan fitur pemantauan energi
 */
public class SmartDoorLock extends SecurityDevice implements EnergyMonitored {
    private int batteryLevel;      // Level baterai (0-100)
    private boolean doorOpen;      // Status pintu (terbuka/tertutup)
    private static final int MAX_BATTERY = 100;
    
    /**
     * Konstruktor untuk membuat SmartDoorLock baru
     * @param name Nama perangkat yang akan ditampilkan
     * @param password Password untuk mengunci/membuka perangkat
     */
    public SmartDoorLock(String name, String password) {
        super(name, password);
        this.batteryLevel = MAX_BATTERY;
        this.doorOpen = false;
    }
    
    /**
     * Mengembalikan jumlah energi yang dikonsumsi (dalam watt)
     * Kalau aktif dia mengerluarkan 2.5 kalau tidak aktif mengeluarkan 0.5
     * Format keluaran: nilai desimal
     * Mengkonsumsi lebih banyak energi ketika aktif
     */
    @Override
    public double getEnergyConsumption() {
        if (isActive()) {
            return 2.5;
        } else {
            return 0.5;
        }
    }
    
    /**
     * Mengembalikan peringkat efisiensi energi berdasarkan level baterai
     * Format keluaran: nilai integer 1-5, dengan 5 adalah yang paling efisien
     * Semakin tinggi baterai, semakin efisien perangkat
     * 0-20% = 1
     * 21-40% = 2
     * 41-60% = 3
     * 61-80% = 4
     * 81-100% = 5
     */
    @Override
    public int getEnergyEfficiencyRating() {
        if (batteryLevel <= 20) {
            return 1;
        } else if (batteryLevel <= 40) {
            return 2;
        } else if (batteryLevel <= 60) {
            return 3;
        } else if (batteryLevel <= 80) {
            return 4;
        } else {
            return 5;
        }
    }
    
    /**
     * Menampilkan status lengkap dari perangkat
     * Format keluaran: multi-baris yang menampilkan nama, status aktif, 
     * status kunci, posisi pintu, level baterai, dan rating efisiensi energi
     */
    @Override
    public void reportStatus() {
        System.out.println("Smart Door Lock Status:");
        System.out.println("- Name: " + deviceName);
        System.out.println("- Active: " + (isActive() ? "Yes" : "No"));
        System.out.println("- Locked: " + (isLocked() ? "Yes" : "No"));
        System.out.println("- Door Position: " + (doorOpen ? "Open" : "Closed"));
        System.out.println("- Battery Level: " + batteryLevel + "%");
        System.out.println("- Energy Rating: " + getEnergyEfficiencyRating() + "/5");
    }
    
    public void openDoor(String password) {
        if (doorOpen) {
            System.out.println("Door is already open");
            return;
        } 
        if (!isActive()) {
            System.out.println("Cannot open door: Device is not active");
            return;
        } 
        if (isLocked()) {
            unlock(password);
        }
        if (!isLocked()) {
            doorOpen = true;
            useBattery(10);
            System.out.println("Door opened");
        }
    }

    public void closeDoor() {
        if (!doorOpen) {
            System.out.println("Door is already closed");
            return;
        }
        doorOpen = false;
        useBattery(5);
        System.out.println("Door closed");
        lock();
    }
    
    public boolean isDoorOpen() {
        return doorOpen;
    }
    

    public void chargeBattery(int amount) {
        if (batteryLevel + amount >= 100) {
            batteryLevel = 100;
        } else {
            batteryLevel += amount;
        }
        System.out.println("Battery charged to " + batteryLevel + "%");
    }
    
    private void useBattery(int amount) {
        if (batteryLevel - amount < 0) {
            batteryLevel = 0;
        } else {
            batteryLevel -= amount;
        }
        if (batteryLevel <= 0) {
            turnOff();
            System.out.println("Warning: Battery depleted, device turned off");
        } else if (batteryLevel < 20) {
            System.out.println("Warning: Low battery (" + batteryLevel + "%)");
        }
    }
   
    @Override
    public void turnOn() {
        if (batteryLevel <= 0) {
            System.out.println("Cannot turn on: Battery depleted");
            return;
        }
        super.turnOn();
        useBattery(5);
    }
    
    @Override
    public void unlock(String password) {
        if (batteryLevel <= 0) {
            System.out.println("Cannot unlock: Battery depleted");
            return;
        }
        super.unlock(password);
        useBattery(8);
    }
}
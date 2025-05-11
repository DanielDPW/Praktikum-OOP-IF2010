public class NPC extends Unit implements Interactable {
    private String dialogue;

    public NPC() {
        super("NPC1", 100);
        this.dialogue = "Hello there!";
    }

    public NPC(String name, int health, String dialogue) {
        super(name, health);
        this.dialogue = dialogue;
    }

    public String getDialogue() {
        return dialogue;
    }

    public void setDialogue(String dialogue) {
        this.dialogue = dialogue;
    }

    public void interact() {
        System.out.println(dialogue);
    }

    public String toString() {
        return getName() + " [Health: " + getHealth() + ", Dialogue: " + getDialogue() +"]";
    }
}
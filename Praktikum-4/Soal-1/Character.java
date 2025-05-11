public class Character extends Unit implements Damageable  {
    private int score;

    public Character() {
        super("Player1", 100);
        this.score = 0;
    }

    public Character(String name, int health, int score) {
        super(name, health);
        this.score = score;
    }

    public int getScore() {
        return score;
    }

    public void setScore(int score) {
        this.score = score;
    }

    public void takeDamage(int damage) {
        setHealth(getHealth() - damage);
        if (getHealth() <= 0) {
            System.out.println(getName() + " has been defeated");
        }
    }

    public void increaseScore(int points) {
        this.score += points;
    }

    @Override
    public String toString() {
        return getName() + " [Health: " + getHealth() + ", Score: " + getScore() +"]";
    }
}
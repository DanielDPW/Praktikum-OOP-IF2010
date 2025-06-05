import java.util.List;
import java.util.ArrayList;

public class WorkerV2 implements Runnable {

    private List<Task> tasks;

    public WorkerV2(){
        this.tasks = new ArrayList<>();
    };

    public void addTask(Task newTask){
        tasks.add(newTask);
    }

    @Override
    public void run() {
        try {
            for (Task t : tasks) {
                Thread.sleep(t.getTime());
                synchronized (t) {
                    t.setStatus("done");
                    t.notify();
                }
            }
        } catch (InterruptedException e) {
            System.out.println("Worker Error!");
        }
    }
    
}

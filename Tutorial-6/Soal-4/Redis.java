import java.util.Objects;

public class Redis<K, V> {
    private K key;
    private V value;
    private long ttl;

    public Redis(K k, V v, long ttl) {
        if (ttl <= 0) {
            throw new InvalidTtlException("TTL must be positive");
        }
        this.key = k;
        this.value = v;
        this.ttl = ttl;
    }

    public K getKey() {
        return key;
    }

    public V getVal(long elapsedSeconds) {
        if (elapsedSeconds >= ttl) {
            throw new TtlExpiredException(key + " expired");
        }
        return value;
    }

    public void setKey(K k) {
        this.key = k;
    }

    public void setVal(V v) {
        this.value = v;
    }

    public long getRemainingTtl(long elapsedSeconds) {
        return ttl > elapsedSeconds ? ttl - elapsedSeconds : 0;
    }

    public void refresh(long newTtl) {
        if (newTtl <= 0) {
            throw new InvalidTtlException("TTL must be positive");
        }
        this.ttl = newTtl;
    }

    boolean isEqual(Redis<?, ?> c) {
        return Objects.equals(this.key, c.key) && Objects.equals(this.value, c.value);
    }

    int nearEQ(Redis<?, ?> c) {
        if (isEqual(c)) {
            return 3;
        } else if (Objects.equals(this.key, c.key)) {
            return 1;
        } else if (Objects.equals(this.value, c.value)) {
            return 2;
        } else {
            return 0;
        }
    }
}
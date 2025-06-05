public class Email {
    private String email; 
    public Email(String email) {
        this.email = email;
    };
    
    public boolean validateEmail() throws InvalidEmailException, InvalidDomainException {
        if (email.isEmpty()) {
            throw new InvalidEmailException("Email tidak boleh kosong");
        }

        if (email.indexOf("@") != email.lastIndexOf("@") || email.indexOf("@") == -1) {
            throw new InvalidEmailException("Email harus mengandung tepat satu buah @");
        }

        if (email.indexOf("@") == 0) {
            throw new InvalidEmailException("@ tidak boleh di awal email");
        }

        int atLoc = email.indexOf("@");
        if (atLoc == email.length() - 1) {
            throw new InvalidDomainException();
        } 
        String domain = email.substring(atLoc + 1);
        

        if (domain.isEmpty() || (domain.indexOf(".") != domain.lastIndexOf(".") || domain.indexOf(".") == -1) || domain.indexOf(".") == 0 || domain.indexOf(".") == domain.length() - 1) {
            throw new InvalidDomainException();
        }

        return true;
    }
}

class InvalidEmailException extends Exception {
    public InvalidEmailException(String message) {
        super(message);
    }
}

class InvalidDomainException extends Exception {
    public String getMessage() {
        return "Email harus memiliki domain yang valid";
    }
}
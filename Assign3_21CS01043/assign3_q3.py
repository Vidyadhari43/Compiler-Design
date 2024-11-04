import re

class RecursiveDescentParser:
    def __init__(self, ip_str):
        # Normalize the input string by removing extra spaces
        self.tokens = re.findall(r'id|\(|\*|\)|\+|\d+', ip_str.replace(' ', ''))
        self.position = 0

    def parse(self):
        result = self.E()
        if result and self.position == len(self.tokens):
            print("Accepted")
        else:
            print("Not Accepted")

    def T(self):
        print(f"Attempting T with input: {' '.join(self.tokens[self.position:])}")
        if self.F():
            return self.T_prime()
        return False
    
    def E(self):
        print(f"Attempting E with input: {' '.join(self.tokens[self.position:])}")
        if self.T():
            return self.E_prime()
        return False

    def F(self):
        print(f"Attempting F with input: {' '.join(self.tokens[self.position:])}")
        if self.match_exist('('):
            if self.E():
                if self.match_exist(')'):
                    return True
                else:
                    return False
            return False
        elif self.match_exist('id'):
            return True
        return False

    def E_prime(self):
        print(f"Attempting E' with input: {' '.join(self.tokens[self.position:])}")
        if self.match_exist('+'):
            if self.T():
                return self.E_prime()
            return False
        return True  # E' can also be empty (epsilon)

    def T_prime(self):
        print(f"Attempting T' with input: {' '.join(self.tokens[self.position:])}")
        if self.match_exist('*'):
            if self.F():
                return self.T_prime()
            return False
        return True  # T' can also be empty (epsilon)

    def match_exist(self, token):
        if self.position < len(self.tokens) and self.tokens[self.position] == token:
            print(f"Matched token '{token}', remaining input: {' '.join(self.tokens[self.position+1:])}")
            self.position += 1
            return True
        return False

def main():
    ip_str = input("Enter the input string: ")
    parser = RecursiveDescentParser(ip_str)
    parser.parse()

# if __name__ == "__main__":
main()
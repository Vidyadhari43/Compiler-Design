class NonTerminal:
    def __init__(self, name):
        self.name = name
        self.rules = []

    def addRule(self, rule):
        self.rules.append(rule)

    def setRules(self, rules):
        self.rules = rules

    def getName(self):
        return self.name

    def getRules(self):
        return self.rules

    def printRule(self):
        print(self.name + " -> ", end="")
        for i in range(len(self.rules)):
            print(self.rules[i], end="")
            if i != len(self.rules) - 1:
                print(" | ", end="")
        print()


class Grammar:
    def __init__(self):
        self.nonTerminals = {}

    def addRule(self, rule):
        # Split the rule into the non-terminal and its productions
        non_terminal, productions = rule.split("->")
        non_terminal = non_terminal.strip()
        productions = [p.strip() for p in productions.split("|")]

        # Check if the non-terminal already exists, if not create it
        if non_terminal not in self.nonTerminals:
            self.nonTerminals[non_terminal] = NonTerminal(non_terminal)

        # Add each production to the non-terminal
        for production in productions:
            self.nonTerminals[non_terminal].addRule(production)

    def inputData(self):
        num_rules = int(input("Enter the number of production rules: "))
        for _ in range(num_rules):
            rule = input("Enter a production rule: ")
            self.addRule(rule)

    def solveNonImmediateLR(self, A, B):
        nameA = A.getName()
        nameB = B.getName()

        rulesA = A.getRules()
        rulesB = B.getRules()
        newRulesA = []

        for rule in rulesA:
            if rule.startswith(nameB):
                for ruleB in rulesB:
                    newRulesA.append(ruleB + rule[len(nameB):])
            else:
                newRulesA.append(rule)
        A.setRules(newRulesA)

    def solveImmediateLR(self, A):
        name = A.getName()
        newName = name + "'"

        alphas = []
        betas = []
        rules = A.getRules()

        # Check if there is left recursion or not
        for rule in rules:
            if rule.startswith(name):
                alphas.append(rule[len(name):])
            else:
                betas.append(rule)

        # If no left recursion, exit
        if not alphas:
            return

        if not betas:
            return
        else:
            newRulesA = [beta + newName for beta in betas]

        newRulesA1 = [alpha + newName for alpha in alphas]
        newRulesA1.append("\u03B5")  # Add epsilon

        # Amends the original rule
        A.setRules(newRulesA)

        # Adds new production rule
        newNonTerminal = NonTerminal(newName)
        newNonTerminal.setRules(newRulesA1)
        self.nonTerminals[newName] = newNonTerminal

    def applyAlgorithm(self):
        nonTerminalList = list(self.nonTerminals.values())
        size = len(nonTerminalList)
        for i in range(size):
            for j in range(i):
                self.solveNonImmediateLR(nonTerminalList[i], nonTerminalList[j])
            self.solveImmediateLR(nonTerminalList[i])

    def printRules(self):
        for nonTerminal in self.nonTerminals.values():
            nonTerminal.printRule()


# Create an instance of the Grammar class
grammar = Grammar()
grammar.inputData()  # Get production rules from user input
grammar.applyAlgorithm()  # Apply the left recursion elimination algorithm
grammar.printRules()  # Print the resulting production rules

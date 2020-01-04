# Jacy the Programming Language

* * *

## The compiler

### Stream
Stream operates with code text.
Provides functions to go through code and stores line-cursor values.

### Lexer

* * *

## Jacy Specification (JC_01)

### Code basics

#### Lines separating
All lines must be separated with semicolon (`;`)

### Variables

#### Scopes


#### Init/Declare/Assign
In JC_01 variables are being inited as their first assignment, but syntax like `a;` is possible too.
Examples:

```
a; // The variable `a` is declared
a = 10; // The variable `a` is assigned to 10
b = 10; // The variable `b` is inited with value 10
```

Some code specials:

```
for(a in [ 1, 2, 3 ]){
    // This is a block, so all the variables that were created on its level will be only available inside it
    print(a);
}
print(a); // Throws an error, because variable `a` isn't declared in this scope
```


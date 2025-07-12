## 📦 C String Functions with Examples (`<string.h>`)

> This guide provides a comprehensive overview of commonly used string functions in C, along with examples to illustrate their usage. Each function is explained with its purpose, code snippet, and expected output.

### 1. `strlen()`

**✅ Purpose:** Find the length of a string (excluding `'\0`')

```c
#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Hello World";
    printf("Length = %lu\n", strlen(str));
    return 0;
}
```

**🖨️ Output:**

```
Length = 11
```

---

### 2. `strcpy()`

**✅ Purpose:** Copy one string to another

```c
#include <stdio.h>
#include <string.h>

int main() {
    char src[] = "C Programming";
    char dest[50];
    strcpy(dest, src);
    printf("Copied: %s\n", dest);
    return 0;
}
```

**🖨️ Output:**

```
Copied: C Programming
```

---

### 3. `strncpy()`

**✅ Purpose:** Copy n characters from one string to another

```c
#include <stdio.h>
#include <string.h>

int main() {
    char src[] = "OpenAI";
    char dest[10];
    strncpy(dest, src, 3);
    dest[3] = '\0';  // manually null-terminate
    printf("Partial Copy: %s\n", dest);
    return 0;
}
```

**🖨️ Output:**

```
Partial Copy: Ope
```

---

### 4. `strcat()`

**✅ Purpose:** Concatenate two strings

```c
#include <stdio.h>
#include <string.h>

int main() {
    char str1[50] = "Hello ";
    char str2[] = "World";
    strcat(str1, str2);
    printf("Concatenated: %s\n", str1);
    return 0;
}
```

**🖨️ Output:**

```
Concatenated: Hello World
```

---

### 5. `strcmp()`

**✅ Purpose:** Compare two strings (lexicographically)

```c
#include <stdio.h>
#include <string.h>

int main() {
    char a[] = "apple";
    char b[] = "banana";
    int result = strcmp(a, b);
    printf("Compare result: %d\n", result);
    return 0;
}
```

**🖨️ Output:**

```
Compare result: -1  // because "apple" < "banana"
```

---

### 6. `strchr()`

**✅ Purpose:** Find first occurrence of a character in a string

```c
#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "ChatGPT";
    char *ptr = strchr(str, 'G');
    printf("Found at: %s\n", ptr);
    return 0;
}
```

**🖨️ Output:**

```
Found at: GPT
```

---

### 7. `strstr()`

**✅ Purpose:** Find first occurrence of a substring

```c
#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Artificial Intelligence";
    char *sub = strstr(str, "Intel");
    printf("Substring: %s\n", sub);
    return 0;
}
```

**🖨️ Output:**

```
Substring: Intelligence
```

---

### 8. `strdup()` _(non-standard in some compilers)_

**✅ Purpose:** Duplicate a string (dynamic memory)

```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char *original = "Dynamic";
    char *copy = strdup(original);
    printf("Copy: %s\n", copy);
    free(copy);
    return 0;
}
```

**🖨️ Output:**

```
Copy: Dynamic
```

---

### 9. `memset()`

**✅ Purpose:** Fill memory with a constant byte

```c
#include <stdio.h>
#include <string.h>

int main() {
    char str[20] = "hello";
    memset(str + 2, '*', 3);
    printf("Modified: %s\n", str);
    return 0;
}
```

**🖨️ Output:**

```
Modified: he***
```

---

### 10. `memcpy()`

**✅ Purpose:** Copy bytes of memory.

```c
#include <stdio.h>
#include <string.h>

int main() {
    char src[] = "CopyMe";
    char dest[10];
    memcpy(dest, src, 7); // including null terminator
    printf("Result: %s\n", dest);
    return 0;
}
```

**🖨️ Output:**

```
Result: CopyMe
```

# Οδηγίες Μεταγλώττισης (Windows / macOS / Linux)

Όλος ο πηγαίος κώδικας του μαθήματος χτίζεται με **ένα ενιαίο, ομοιόμορφο
τρόπο σε όλα τα λειτουργικά συστήματα** μέσω του **CMake**. Δεν χρειάζεται να
ασχοληθείτε με το ποιος compiler είναι εγκατεστημένος (gcc, clang, MSVC) — το
CMake τον εντοπίζει αυτόματα.

Κάθε αρχείο `.c` μέσα στο `src/weekNN/` (και `src/weekNN/exercises/`) γίνεται
**ένα ξεχωριστό εκτελέσιμο πρόγραμμα**.

---

## 1. Εγκατάσταση απαιτούμενων εργαλείων

### Windows

1. Εγκαταστήστε το **[CMake](https://cmake.org/download/)** (επιλέξτε
   "Add CMake to system PATH" κατά την εγκατάσταση).
2. Εγκαταστήστε έναν compiler C. Η ευκολότερη επιλογή είναι το **[MSYS2](https://www.msys2.org/)**
   με το πακέτο MinGW-w64 (`pacman -S mingw-w64-ucrt-x86_64-gcc`), ή
   εναλλακτικά τα **"Build Tools for Visual Studio"** (Desktop development
   with C++) από τη Microsoft.
3. Ανοίξτε το **PowerShell** ή το **"x64 Native Tools Command Prompt"** (αν
   χρησιμοποιείτε MSVC) μέσα στον φάκελο του αποθετηρίου.

### macOS

1. Εγκαταστήστε τα Command Line Tools (περιλαμβάνουν τον compiler `clang`):
   ```
   xcode-select --install
   ```
2. Εγκαταστήστε το CMake, ιδανικά μέσω [Homebrew](https://brew.sh/):
   ```
   brew install cmake
   ```

### Linux (Ubuntu/Debian ως παράδειγμα)

```
sudo apt update
sudo apt install build-essential cmake
```
(Σε Fedora: `sudo dnf install gcc cmake make`. Σε Arch: `sudo pacman -S base-devel cmake`.)

---

## 2. Μεταγλώττιση όλου του μαθήματος (ίδιες εντολές παντού)

Μέσα από τον ριζικό φάκελο του αποθετηρίου (εκεί που βρίσκεται το
`CMakeLists.txt`):

```bash
cmake -S . -B build
cmake --build build
```

- Η πρώτη εντολή («configure») δημιουργεί τον φάκελο `build/` και ανιχνεύει
  τον compiler σας.
- Η δεύτερη εντολή («build») μεταγλωττίζει **όλα** τα προγράμματα.

> Στα Windows με MSVC, το CMake παράγει project του Visual Studio μέσα στο
> `build/`. Η εντολή `cmake --build build` λειτουργεί κανονικά και εκεί,
> χωρίς να χρειάζεται να ανοίξετε το Visual Studio GUI. Αν προτιμάτε το GUI,
> ανοίξτε απλά το `build/C11_Course_ProgrammaC.sln`.

Μετά το build, όλα τα εκτελέσιμα βρίσκονται οργανωμένα σε:

```
build/bin/week01/week01_01_hello_world
build/bin/week01/week01_02_hello_world_me_sxolia
build/bin/week05/week05_04_for_demo
build/bin/week10/week10_ask06_dynamikos_pinakas_tetragwna
...
```

(Στα Windows θα έχουν κατάληξη `.exe`.)

---

## 3. Εκτέλεση ενός προγράμματος

```bash
# Linux / macOS
./build/bin/week01/week01_01_hello_world

# Windows (PowerShell ή cmd)
.\build\bin\week01\week01_01_hello_world.exe
```

---

## 4. Χτίσιμο μόνο μιας συγκεκριμένης εβδομάδας / ενός προγράμματος

Το configure πάντα διαβάζει όλο το `src/`, αλλά μπορείτε να χτίσετε
**επιλεκτικά** μόνο ένα target αντί για όλα, π.χ.:

```bash
cmake --build build --target week06_01_eisagogi_pinakes_i
```

Παράδειγμα target ανάμεσα στις ασκήσεις μιας εβδομάδας (φάκελος `exercises/`):

```bash
cmake --build build --target week10_ask06_dynamikos_pinakas_tetragwna
```

(Δείτε τα διαθέσιμα ονόματα targets με `cmake --build build --target help`.)

---

## 5. Καθαρισμός

Για πλήρη επανεκκίνηση, απλά διαγράψτε τον φάκελο `build/` και ξανατρέξτε το
βήμα 2:

```bash
# Linux/macOS
rm -rf build

# Windows PowerShell
Remove-Item -Recurse -Force build
```

---

## 6. Συνηθισμένα προβλήματα

| Πρόβλημα | Λύση |
|---|---|
| `cmake: command not found` | Το CMake δεν είναι στο PATH — ξανατρέξτε τον installer με "Add to PATH" ή ανοίξτε νέο τερματικό. |
| `undefined reference to 'sqrt'` (Linux) | Δεν θα πρέπει να συμβεί — το `CMakeLists.txt` συνδέει αυτόματα τη libm. Αν συμβεί, ενημερώστε το CMake (`cmake --version`, χρειάζεται ≥ 3.16). |
| Ελληνικοί χαρακτήρες εμφανίζονται σαν "σαλάτα" στην κονσόλα των Windows | Ακριβώς γι' αυτόν τον λόγο όλα τα σχόλια/μηνύματα του πηγαίου κώδικα είναι γραμμένα σε **Greeklish** (λατινικοί χαρακτήρες) — δεν θα πρέπει να συναντήσετε πρόβλημα κωδικοποίησης σε κανένα πρόγραμμα. |
| Προειδοποιήσεις (`-Wall -Wextra`) κατά το χτίσιμο | Είναι φυσιολογικές και σκόπιμες — βοηθούν τους μαθητές να εντοπίζουν πιθανά λάθη. Δεν εμποδίζουν το χτίσιμο (δεν χρησιμοποιούμε `-Werror`). |

---

## 7. Εναλλακτικά περιβάλλοντα εργασίας

Οι μαθητές μπορούν φυσικά να χρησιμοποιήσουν και IDE/online εργαλεία όπως
Code::Blocks, Dev-C++, VS Code, Replit, OnlineGDB ή [pythontutor.com/c.html](https://pythontutor.com/c.html#mode=edit)
για μεμονωμένα αρχεία — το CMake project είναι ο **επίσημος, ενιαίος** τρόπος
να χτίζεται/ελέγχεται όλο το υλικό του μαθήματος με συνέπεια.

# Saisir une valeur au clavier

Voici quelques lignes de code permettant de récupérer une valeur saisie
au clavier dans la console, en fonction du type de données
(l'équivalent des fonctions ExAlgo `lireCaractère()`, `lireEntier()`, etc).
Il faudra importer `java.util.Scanner`.

Ces lignes ne sont pas à connaître par coeur.

### Lire un caractère
```java
Scanner sc = new Scanner(System.in);
String str = sc.nextLine();
char saisie = str.charAt(0);
```

### Lire un entier
```java
Scanner sc = new Scanner(System.in);
int saisie = sc.nextInt();
```

### Lire un réel
```java
Scanner sc = new Scanner(System.in);
double saisie = sc.nextDouble();
```

# Fonction afficheLigne()

Pour réussir ce TP, nous vous donnons le contenu de
la fonction `afficheLigne()`.
Toutes les autres sont à réaliser par vous même.

```java
static void afficheLigne(char car, int min, int taille) {
    for (int i = 0; i < min; i++) {
        System.out.print(" ");
    }
    for (int i = min; i < min + taille; i++) {
        System.out.print(car);
    }
    System.out.println("");
}
```

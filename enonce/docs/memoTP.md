# Java et outils de développement

## De l'algorithme à Java

Une grande partie de ce que nous avons utilisé pour créer les algorithmes est utilisable à l'identique en Java pur. Pas de secret, pour savoir écrire du code, il faut que vous passiez du temps sur votre clavier.

Il vous faudra apprendre par coeur les syntaxes ci-dessous.

### Instructions et commentaires

 * en Java chaque instruction se termine par un **point-virgule**.
 * les **commentaires** s'écrivent de deux manières :
     + `//` pour commenter la fin de la ligne, et
     + `/* ... */` pour commenter un bloc (tout ce qu'il y a entre `/*` et `*/`, potentiellement sur plusieurs lignes).

### Types et variables

* les **types de base** :

 ExAlgo | Java
 --- | ---
 `entier` | `int`
 `réel` | `double`
 `caractère` | `char`
 `booléen` | `boolean`
 
 * la **déclaration** et l'**initialisation** des variables :
     + `Var i : entier` s'écrit en Java `int i;` et
     + l'**affectation** `i ⟵ 2` s'écrit `i = 2;`

```java
int a; // déclaration
a = 1; // initialisation
int b = 3; // déclaration + initialisation
double c = 3.5;
c = 3.0; // écrase la valeur précédente
char d = '@';
boolean e = true;
e = false;
```

 * les **règles de conversion**.
   En général on ne peut pas affecter un contenu d'un certain type dans une
   variable d'un autre type (par exemple un caractère dans un booléen).
   Cela dit on peut affecter un entier dans un réel, mais pas l'inverse
   (perte de précision), ou alors il faut le dire explicitement :

```java
int i = 9;
double d = 2.3;
d = i; // ok, conversion automatique
i = d; //  ne compile pas
i = (int)d; // ok, conversion explicite avec perte de précision
```

 * les **chaînes de caractère**.
   Il y a quelques notions à connaître concernant les chaînes de caractères
   en ce début de semestre. Nous les étudierons plus en détail lors du cycle 4.
   Une *chaîne de caractères* est simplement une suite de caractères :
      * cela correspond au type Java `String`.
      * on peut créer une chaîne simplement en la délimitant par des guillemets.
      * pour concaténer deux chaînes de caractères (c'est-à-dire les "coller"),
     on utilise l'opérateur `+`.
      * Java s'occupe de transformer automatiquement les autres types (entier,
      réel, booléen) en une chaîne lorsqu'on concatène.

```java
String s; // déclaration
s = "Hello"; // initialisation
String t = s + " world!"; // t contient "Hello world!"

int n = 2;
String texte = "Il y a " + n + " projets."; // texte contient "Il y a 2 projets."
```

### Lire et écrire

Dans ce cours nous utiliserons une interface texte pour la lecture
et l'écriture.

#### Lire

Les instructions ExAlgo `lireEntier()`, `lireCaractère()`, etc
se traduisent en Java par quelques instructions
que vous n'avez pas à connaître, et qui vous sont fournies
dans la section [RessourcesTP](ressourcesTP.md).

#### Écrire

L'instruction ExAlgo `ecrireLigne()` se traduit en Java par l'appel à la fonction
`System.out.println(...)`, qui prend comme paramètre une chaîne de caractères.

L'instruction ExAlgo `ecrire()` (sans retour à la ligne) se traduit en Java par 
`System.out.print(...)`.

### Opérateurs

#### Opérateurs arithmétiques

 * sur les entiers et les réels (comme en ExAlgo) : `+`, `-`, `*`, `/`, `%`
 * formes compactes :
     + `i += 2` est équivalent à `i = i + 2`
     + idem pour les 4 autres opérateurs
     + `i++` (plus classique) et `++i` (plus efficace) sont équivalents à `i += 1` (et donc à `i = i + 1`)
     + idem pour `i--` et `--i`

#### Opérateurs de comparaison

 * sur les entiers, réels et caractères :
     + `<`, `<=`, `>`, `>=`
 * sur tous les types :
     + `==` pour tester l'égalité (par exemple `a == 0`)
     + `!=` pour tester la différence (par exemple `a != 0`)

!!! danger "Attention : == vs = vs ⟵"
    Attention, en Java le test s'écrit `==` (et pas `=`) et l'affectation `=` (et pas `⟵`).


#### Opérateurs booléens

 * sur les booléens :
     + `&&` pour le **et**
     + `||` pour le **ou**
     + `!`  pour le **non**
 * `&&` et `||` disposent aussi d'une forme compacte :
     + `trouve |= (n == 3)` est équivalent à : `trouve = trouve || n == 3`.

Exemple :

```java
int a = 1;
int b = 3;
int c = a + b; // c vaut 4
boolean d = (a > b); // d vaut false
d = (a == b); // d vaut false
d = (a < b);  // d vaut true
d &= (a != b); // d vaut true
d = (a > c || !d); // d vaut false
```  

### Structures conditionnelles

Les structures conditionnelles (`if`/`else`) sont une simple traduction
de celles utilisées dans les algorithmes (`Si`/`Alors`/`Sinon`).

Par exemple ce bout d'algorithme :
```{ .exalgo use_pygments=false }
Si x > y Alors
    ecrire("L'entier " + x + " est strictement supérieur à l'entier " + y)
Sinon Si x < y Alors
    ecrire("L'entier " + x + " est strictement inférieur à l'entier " + y)
Sinon
    ecrire("L'entier " + x + " est égal à l'entier " + y)
```

s'écrit en Java :
```java
if (x > y) {
    System.out.println("L'entier " + x + "est strictement supérieur à l'entier " + y);
} else {
    if (x < y) {
        System.out.println("L'entier " + x + "est strictement inférieur à l'entier " + y);
    } else {
        System.out.println("L'entier " + x + "est égal à l'entier " + y);
    }
}
```

* les blocs sont délimités par des accolades `{ ... }`.
* les blocs peuvent être **imbriqués** (un bloc dans un bloc)
comme dans l'exemple ci-dessus.
* les blocs *doivent* être **indentés** (c'est-à-dire que les instructions d'un
bloc doivent être alignées verticalement, et décalées d'un bloc à l'autre).
L'indentation n'est pas exigée par Java, mais exigée par les humains pour
avoir un code lisible.
* le bloc `else` est facultatif.
* les accolades sont facultatives lorsque le bloc ne comporte
qu'une seule instruction.
Mais nous recommandons fortement de *mettre systématiquement les accolades*.
La seule exception est l'enchaînement des blocs `if`/`else`
comme dans l'exemple ci-dessus, que l'on peut écrire :
```java
if (x > y) {
    System.out.println("L'entier " + x + "est strictement supérieur à l'entier " + y);
} else if (x < y) {
        System.out.println("L'entier " + x + "est strictement inférieur à l'entier " + y);
} else {
        System.out.println("L'entier " + x + "est égal à l'entier " + y);
}
```


### Fonctions


![type:image](img/fonctions.jpg){: style="width:60%;"}

La déclaration de fonctions est proche de celle vue en algo. Il faut :

- un **nom** de fonction,
- des **paramètres**,
- un **type de retour** (utiliser le mot-clef `void` si la fonction ne retourne rien). Si un type de retour est déclaré, le mot-clé `return` est utilisé pour retourner une valeur à la fin de la fonction.

#### Exemple de fonction sans paramètre, avec type de retour
En ExAlgo :
```{ .exalgo use_pygments=false }
Fonction fct1() : entier
    Début
        Retourner 4
    Fin
```
En Java (le mot clef `static` sera systématiquement utilisé pour l'instant,
nous verrons plus tard ce qu'il signifie) :
```java
// déclaration de la fonction
static int fct1() {
    return 4; 
}

   ...
   // appel de cette fonction (depuis une autre fonction)
   int resultat = fct1();
   // resultat vaut 4;
```

#### Exemple de fonction avec paramètre, sans type de retour

En ExAlgo :
```{ .exalgo use_pygments=false }
Fonction fct2(E a : entier)
    Début
      ecrire("l'argument vaut : " + a)
    Fin
```

En Java :
```java
// déclaration de la fonction
static void fct2(int a) {
    System.out.println("la variable vaut " + a);
    // rien à retourner
}

    ...
    // appel de cette fonction (depuis une autre fonction)
    fct2(-1);  // affiche "la variable vaut -1"
    fct2(0);   // affiche "la variable vaut 0"
    fct2(120); // affiche "la variable vaut 120"
    // rien à récupérer (on ne peut pas faire int valeur = fct2(4)) car fct2 ne retourne rien
```

#### Exemple de fonction avec paramètres et type de retour

En ExAlgo :
```{ .exalgo use_pygments=false }
Fonction fct3(var a : entier, var b : booléen) : caractère
    Var resultat : caractère
    Début
        Si (b et a == 0) Alors
            resultat ⟵ '@'
        Sinon
            resultat ⟵ 'X'
        Fin
        Retourner resultat
    Fin
```

En Java :
```java
static char fct3(int a, boolean b) {
    char resultat;
    if (b && a == 0) {
        resultat = '@';
    } else {
        resultat = 'X';
    }
    return resultat;
}

    ...
    // appel de cette fonction (depuis une autre fonction)
    char retour;
    retour = fct3(0, true);  // retour vaut '@'
    retour = fct3(0, false); // retour vaut 'X'
    retour = fct3(10, true); // retour vaut 'X'
```


## Méthodologie

Cette méthodologie ne vous sera pas redonnée dans les autres cycles.
Voici le *cycle de développement* que vous devez suivre
pour chaque fonctionnalité codée (une fois son algorithme établi) :

1. créer un **"squelette"** vide de la fonction : sa signature, et un `return` si besoin (et aussi sa documentation : nous verrons cela au cycle 1).
2. rédiger les **tests unitaires** (voir JUnit ci-dessous).
3. rédiger le **code** de la fonction.
4. **lancer les tests unitaires**.
5. si les tests révèlent des erreurs, les **corriger** à l'aide du debugger
   (voir ci-dessous) et reprendre à l'étape, jusqu'à ce que les tests passent.

!!! exo "Projet initial"
    Créez donc un projet NetBeans (comme vu dans la partie Installation) :
    
    - Project Name: `Cycle0`
    - Project Location: dans votre dossier `R1.01_AlgoProg/TP`
    - Create Main Class : `formes.Formes`.

Nous allons illustrer cette méthodologie avec la fonction `formeCorrecte()` (dont nous avons déjà rédigé les cas de test dans la partie [Descriptif](index.md)).

!!! exo "1. Squelette de `formeCorrecte()`"
    Relisez la définition de cette fonction dans la partie [Descriptif](index.md).
    Dans la classe `Formes`, ajoutez la fonction suivante, par exemple
    après le `main()` :

```java
static char formeCorrecte(int niveau) {
    return 'a';
}
```

## JUnit

![type:image](img/tests.jpg){: style="width:60%;"}

JUnit est une bibliothèque Java permettant de coder des tests unitaires.

Dans chaque projet NetBeans (dans l'arborescence de gauche) apparaît :

- `Source Packages` : emplacement du code source
- `Test Packages` : emplacement des tests unitaires.

!!! note "Si `Test Packages` n'existe pas..."

    - clic droit sur le projet (à gauche), `New`, `Folder`, mettre `test` comme nom de répertoire
    - normalement `Test Packages` apparaît dans l'onglet `Projects`
    - clic droit sur `Test Packages`, `New`, `Java package...`, mettre le même nom de package (ici `formes`)

### Fonctions de test

!!! exo "Fichier (et classe) de tests"
    Faire un clic droit **sur le package `formes`** (de `Test Packages`),
    et choisir `New` / `Java Class...`
    et créer ainsi la classe `FormesTest`.
    Y créer la fonction **testFormeCorrecte()** avec le code ci-dessous :

```java
package formes;

import org.junit.Test;

public class FormesTest {

    @Test
    public void testFormeCorrecte() {
       // écrire les tests unitaires ici
    }
}
```

Les fonctions de test doivent suivre certaines règles :

- **l'annotation `@Test`** permet à JUnit d'identifier les fonctions qui sont des tests unitaires. Remarque : si une annotation `@Test` ne compile pas, importez la bibliothèque JUnit comme suggéré par NetBeans (bibliothèque `org.junit....`).
- les fonctions de test doivent être déclarées **`public void` et ne pas prendre de paramètre**.

!!! note "Si les bibliothèques JUnit ne vous sont pas proposées..."
    Dans ce cas il faut les ajouter dans votre projet :

    - sélectionner le projet (à gauche), clic droit, `Properties`,
    - catégorie `Libraries`, onglet `Compile Tests`
    - dans `Classpath`, cliquer sur `+` / `Add Library...`
    - ajouter `JUnit4` et `Hamcrest` (avec leur version courante).
    

### Méthodes de test

JUnit propose différentes méthodes pour rédiger un test, selon sa nature (vérifier une valeur calculée, vérifier une valeur booléenne...) :

Méthode | Description
--- | ---
`assertEquals(valeurAttendue, valeurCalculee)` | s'assure que `valeurCalculee` vaut bien le résultat attendu, c'est-à-dire `valeurAttendue`
`assertEquals(valeurAttendue, valeurCalculee, delta)` | idem, mais pour les réels (`double`). Ici, `delta` est le degré de précision au-delà duquel deux nombres sont considérés égaux
`assertTrue(monTest)` | s'assure que le booléen `monTest` est `vrai`
`assertFalse(monTest)` | s'assure que le booléen `monTest` est `faux`

!!! exo "2. Rédiger les tests unitaires"
    Rédigez les tests unitaires, en complétant le code de
    `testFormeCorrecte()` avec les cas de test proposés dans
    la section [Descriptif](index.md).
    Votre code doit ressembler à ceci (à compléter) :

```java
@Test
public void testFormeCorrecte() {
    assertEquals('c', Formes.formeCorrecte(1));
    assertEquals('c', Formes.formeCorrecte(2));
    // à compléter...
}
```
Notez que pour appeler `formeCorrecte()`, on l'a fait précéder du nom
de la classe (`Formes`) car on se trouve dans une autre classe (`FormesTest`).

### Lancer les tests

Il y a plusieurs façons de lancer les tests unitaires, selon ce que l'on veut faire (nous évoquerons le mode debug juste après) :

Objectif | Action
--- | ---
lancer tous les tests d'une classe | clic droit sur le fichier (à gauche), puis `Test File`
idem, mais en mode debug | clic droit sur le fichier (à gauche), puis `Debug Test File`
lancer un test unitaire (une méthode) | clic droit sur le nom de la méthode, puis `Run Focused Test Method`
idem, en mode debug | clic droit sur le nom de la méthode, puis `Debug Focused Test Method`

Lorsque vous exécutez ces tests, une fenêtre s'ouvre et vous indique les tests réussis et ceux qui ont échoué.

![type:image](img/testsOK.png)
![type:image](img/testsNOK.png)

!!! note "Message d'erreur `Target method "debug-single-method" does not exist in the project...`"
    Lorsqu'on débugge un test unitaire (une seule méthode, via `Debug focused test method`), il arrive que le test ne se lance pas, et que le message ci-dessus apparaisse. Dans ce cas, il faut éditer le fichier `nbproject/build-impl.xml` (depuis le répertoire du projet), dupliquer la ligne contenant `debug-test-method` et changer cette chaîne par `debug-single-method` dans la ligne copiée.

!!! exo "Lancez le test `testFormeCorrecte()`"
    Essayez de deux manières :
    
    - en lançant tous les tests de `FormesTest`,
    - en lançant uniquement `testFormeCorrecte()`.

    Normalement le test ne passe pas.

### Coder et relancer

!!! exo "3. Rédiger le code de la fonction"
    Il est maintenant temps de rédiger réellement le code de la
    fonction `formeCorrecte()`, dans la classe `Formes`.
    Nous en avons déjà rédigé l'algorithme dans la section [Descriptif](index.md).
    Votre code devrait ressembler à ceci :

```java
static char formeCorrecte(int niveau) {
    char forme = ' ';
    if (niveau == 1 || niveau == 2) {
        forme = 'c';
    } else if (niveau == 3 || niveau == 4) {
        forme = 't';
    }
    return forme;        
}   
```

!!! exo "4. Lancer les tests unitaires"
    Relancer les tests unitaires dans `testFormeCorrecte()`.
    Vérifier qu'ils passent.

## Debug

Lorsque vos tests unitaires ne passent pas,
il est indispensable de debugger votre code.
Cela consiste à faire tourner votre programme pas à pas, en pouvant consulter
l'état de la mémoire (les valeurs des variables).

Pour cela il faut poser un point d'arrêt (en cliquant sur le numéro
de la ligne) sur la première ligne de code de votre fonction.
Celle-ci passe sur fond rouge.

On peut ensuite :

- lancer **le programme** en mode debug,
  via `Debug project` (icône, ou dans le menu `Debug`), ou
- lancer **les tests unitaires** en mode debug (voir JUnit ci-dessus).

Comme sur l'image ci-dessous, l'exécution s'arrêtera sur la ligné désirée.

![type:image](img/debug1.png)

Vous pouvez accéder au contenu des variables du code déjà exécuté.
Sur l'image ci-dessous on voit que le contenu de la variable `nbMax`
vaut `10` et la variable `difficulte` vaut `1`.

![type:image](img/debug2.png)

Vous pouvez  exécuter le code ligne par ligne en appuyant sur l'icône entourée en rouge (`Step Over`, <kbd>F8</kbd>).

![type:image](img/debug3.png)

Les icônes suivantes sont aussi à connaître :

- `Continue` (<kbd>F5</kbd> ou flèche verte) permet de continuer l'exécution jusqu'au prochain point d'arrêt,
- `Step Into` (<kbd>F7</kbd> ou flèche vers le bas) est similaire à `Step Over`,
  mais s'il y a un appel de fonction sur la ligne, rentre dans la fonction.

!!! exo "5. Corriger"
    - Introduire un bug dans `formeCorrecte()`.
    - Vérifier que les tests ne passent plus.
    - Pauser un point d'arrêt dans `formeCorrecte()`.
    - Relancer les tests en mode debug et tester les différentes fonctionnalités
      du debugger (ci-dessus) pour trouver le bug.
    - Corriger le bug et relancer les tests.

# Trame

!!! exo "Voici une proposition de trame pour commencer votre développement :"

    - créer le squelette de `jeuForme()`, et implémenter le début avec la saisie
    du niveau.
    - appeler `jeuForme()` depuis le `main()`, lancer votre projet
    - créer le squelette de `jouerUnNiveau()`
    - terminer `jeuForme()` avec notamment un appel à `jouerUnNiveau()`. Relancer.
    - continuer en codant `jouerUnNiveau()` et les fonctions qu'elle appelle...
    - n'oubliez pas de coder les tests unitaires pour les fonctions
    qui "calculent" quelque chose (pas les fonctions d'affichage / saisie).
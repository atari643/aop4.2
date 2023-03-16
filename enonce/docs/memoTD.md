# Les bases de l'ExAlgo

## Les variables

!!! note inline "Une variable possède "
    * un nom qui permet d’y accéder,
    * un type qui caractérise l’ensemble des valeurs que peut prendre la variable,
    * une valeur qui peut changer dans le temps.

### Exemple

``` { .exalgo use_pygments=false }
Var saisie : caractère
saisie ⟵ 'r'
```

1. La ligne 1 correspond à **la déclaration**
d'une variable nommée `saisie`, de type `caractère` grâce au mot-clé `Var`.
2. La ligne 2 correspond à **l'initialisation **
de cette variable avec le caractère `r`.

Donc :

* nom : `saisie`
* type : `caractère`
* valeur : `le caractère 'r'`

!!! convention "Convention"
    Les noms des variables doivent être en *CamelCase*,
    c'est-à-dire en minuscule,
    sauf pour la première lettre de chaque mot (excepté le premier qui reste en
    minuscule) : `noteMaths`, `temperatureExterieure`, etc.


### Connaître les 4 types de base

* **entier** : -123, -4, 0, 3, 76 ...
* **réel** : -94.03, -3.0, 0.0, 1.324, 4.0, ...
* **caractère** : 'a', 'b', '@', '*', '😀', '4', 'A', 'B', ...
* **booléen** : vrai, faux


### Savoir déclarer, initialiser et afficher le contenu d'une variable

Nous décomposons ci-dessous un seul et même algorithme,
permettant de lire des données au clavier, et d'écrire sur l'écran.

**Déclarer** et **initialiser** les variables :

```{ .exalgo use_pygments=false }
Var a : entier
Var b : réel
Var c : caractère
Var d : booléen
a ⟵ 2
b ⟵ 3.3
c ⟵ 'T'
d ⟵ vrai
```

!!! convention "Convention"
    Une variable doit **toujours être initialisée** par votre code,
    avant d'être utilisée. On ne doit pas se baser sur les valeurs par défaut,
    comme le précise la [doc Java](https://docs.oracle.com/javase/tutorial/java/nutsandbolts/datatypes.html) :

    <cite>Relying on such default values, however, is generally considered bad programming style.</cite>

**Afficher à l'écran** avec la fonction `ecrire()` :
(l'opérateur '+' permet de concaténer du texte avec des contenus de variables)
```{ .exalgo use_pygments=false }
ecrire("a = " + a)
```
donne l'affichage :  `a = 2`, et :

```{ .exalgo use_pygments=false }
ecrire("a = " + a + " b = " + b + " c = " + c + " d = " + d)
```
donne l'affichage :  `a = 2 b = 3.3 c = T d = vrai`

**Saisir une valeur au clavier** et l'affecter à une variable :
```{ .exalgo use_pygments=false }
a ⟵ lireEntier()
c ⟵ lireCaractère()
```
On suppose que l'utilisateur a saisi `24` puis `@` au clavier.

```{ .exalgo use_pygments=false }
ecrire("a = " + a)
ecrire(" c = " + c)
```
donne alors l'affichage : `a = 24 c = @`.
Pour passer à la ligne après avoir écrit, on utilise `ecrireLigne()` :

```{ .exalgo use_pygments=false }
ecrireLigne("a = " + a)
ecrire("c = " + c)
``` 
donne l'affichage :  
```
a = 24
c = @
```

### Typage

Une fois que l'on a précisé le type d'une variable :

- cette variable ne peut plus en changer, et
- le contenu de cette variable doit obligatoirement être du même type.

Nous verrons également en TP les règles de conversion
entre **entier** et **réel**.

## Les opérations entre variables
    
!!! note "Entre entiers"
    * `1 + 2` vaut `3`
    * `1 - 2` vaut `-1`
    * `1 * 2` vaut `2`
    * `5 / 2` vaut `2` (division entière)
    * `5 % 2` vaut `1` (reste de la division entière, également appelé "modulo")

!!! note "Entre réels"
    * `1.0 + 2.0` vaut `3.0`
    * `1.2 - 2.3` vaut `-1.1`
    * `10.0 * 2.31` vaut `23.1`
    * `5.0 / 2.0` vaut `2.5` (division réelle)

!!! note "Entre booléens"
    * "et" logique
        * `faux et faux` vaut `faux`
        * `faux et vrai` vaut `faux`
        * `vrai et faux` vaut `faux`
        * `vrai et vrai` vaut `vrai`
    * "ou" logique
        * `faux ou faux` vaut `faux`
        * `faux ou vrai` vaut `vrai`
        * `vrai ou faux` vaut `vrai`
        * `vrai ou vrai` vaut `vrai`
    * "non" logique
        * `non vrai` vaut `faux`        
        * `non faux` vaut `vrai`

!!! note "Opérateurs de comparaison"
    *  `>`, `>=`, `<`, `<=`, `==`, `!=`
        * `3 > 2` vaut `vrai`
        * `3 >= 2` vaut `vrai`
        * `2 > 2` vaut `faux`
        * `2 >= 2` vaut `vrai`
        * `3 == 3` vaut `vrai`
        * `3 == 2` vaut `faux`
        * `3 != 3` vaut `faux`
        * `3 != 2` vaut `vrai`
	* idem pour les nombres réels (`3.07 >= 12.2`).
	Attention toutefois à la comparaison (par exemple `2.999` et `3.000`) :
	on compare avec un certain degré de précision.

## Les conditions

### L'instruction Si 

``` { .exalgo use_pygments=false }
Si /* expression booléenne */ Alors
    // instructions réalisées si l’expression a été évaluée à VRAI
Sinon
    // instructions réalisées si l’expression a été évaluée à FAUX
```

### Exemple

``` { .exalgo use_pygments=false }
Var x, y : entiers
x ⟵ lireEntier()
y ⟵ lireEntier() 
Si x > y Alors
    écrire("L'entier " + x + " est strictement supérieur à l'entier " + y)
Sinon Si x < y Alors
    écrire("L'entier " + x + " est strictement inférieur à l'entier " + y)
Sinon
    écrire("L'entier " + x + " est égal à l'entier " + y)
```

``` mermaid
graph TD
    DEB(["Début"]) --> A
    A["x⟵lireEntier()"] -->B["y⟵lireEntier()"]
    B --> C{Si x > y}
    C -->|vrai| D["Écrire x > y"]
    C -->|faux| E{Si x < y} 
    E -->|vrai| F["Écrire x < y"]
    E -->|faux| G["Écrire x = y"]
    D --> FIN
    F --> FIN
    G --> FIN
    FIN(["Fin"])
```

## Les fonctions

### Signature

L'intérêt d'une fonction est de diviser un gros problème en une succession de sous-problèmes simples à résoudre.

* Les fonctions peuvent (ou pas) avoir des **paramètres d'entrée**. Ces paramètres ont des "modes de passage" : *E (entrée)* ou *ES (entrée/sortie)*. Cette notion sera vue plus tard, pour le moment nous utiliserons toujours le mode E.
* Les fonctions peuvent **retourner une (et une seule) valeur**, ou **ne rien retourner**.

Une fonction a une **signature** (parfois appelé **prototype**) qu'il faut savoir reconnaître :
``` { .exalgo use_pygments=false }
Fonction nom(E paramètre1 : type, E paramètre2 : type, ..., E paramètreN : type) : type de retour éventuel
```

#### Exemples

##### Pas de paramètre mais un retour

``` { .exalgo use_pygments=false }
Fonction fct1() : entier
```

Le nom de cette fonction est `fct1`.
Elle a 0 paramètre en entrée et retourne un entier.


``` mermaid
flowchart TB
        deb[" "]-.->|pas de paramètres| fct1        
        subgraph fct1["fct1() : entier"]
        a1[lignes de codes]
        end
        fct1-.->|un entier retourné au code qui a appelé cette fonction| a2[" "]
```

##### Un paramètre mais pas de retour

``` { .exalgo use_pygments=false }
Fonction fct2(E a : entier)
```

Fonction dont le nom est `fct2`. 
Elle a 1 paramètre de type entier en entrée et ne retourne rien.
Dans le corps de `fct2()`, si vous voulez
avoir accès à la valeur passée en paramètre
il faudra manipuler la variable `a`.

``` mermaid
flowchart TB
        deb[" "]-.->|un entier en paramètre| fct2
        subgraph fct2["fct2(E a : entier)"]
        a1["lignes de codes
        le contenu de la variable a est accessible 
        uniquement dans cette fonction"]
        end
        fct2-.->|rien n'est retourné au code qui a appelé cette fonction| a2[" "]
```

##### Des paramètres et un retour

``` { .exalgo use_pygments=false }
Fonction fct3(E a : entier, E b : booléen) : caractère
```

Fonction dont le nom est `fct3`. 
Elle a 2 paramètres. Un de type entier et l'autre de type booléen.
Elle retourne un caractère.
Dans le corps de cette fonction, on pourra manipuler les variables `a` et `b`.

``` mermaid
flowchart TB
        deb[" "]-.->|un entier et un booléen en paramètres| fct3
        subgraph fct3["fct3(E a : entier, E b : booléen) : caractère"]
        a1["lignes de codes
        le contenu des variables a et b sont accessibles 
        uniquement dans cette fonction"]
        end
        fct3-.->|un caractère est retourné au code qui a appelé cette fonction| a2[" "]
```

### Corps

Après la signature, le corps de la fonction se découpe en deux parties :

- la déclaration des variables, signalée par le mot-clé `Var`.
- le code, délimité par les mots-clés `Début` et `Fin`,
  et comprenant une instruction `Retourner`
  pour les fonctions retournant une valeur.

!!! note "Retour de fonction"
    Attention : au S1, un seul `Retourner` par fonction !

#### Exemple

``` { .exalgo use_pygments=false }
Fonction somme(E n1 : entier, E n2 : entier) : entier
    Var s : entier
    Début
        s ⟵ n1 + n2
        Retourner s
    Fin
```

La déclaration des variables n'est pas toujours nécessaire.
On aurait ainsi pu écrire :

``` { .exalgo use_pygments=false }
Fonction somme(E n1 : entier, E n2 : entier) : entier
    Début
        Retourner n1 + n2
    Fin
```

### Appel

Bien sûr une fonction n'a d'intérêt que lorsqu'elle est **appelée**,
c'est-à-dire lorsque l'on demande l'exécution de son code :

- avec certaines valeurs pour ses paramètres (que l'on appelle **arguments**),
et
- en récupérant (le cas échéant) sa **valeur de retour**.

Tout ceci en respectant les *types* (si la fonction attend un réel comme
argument, on ne peut pas lui envoyer un caractère, etc).

#### Exemple

Regardons par exemple l'algorithme suivant :

``` { .exalgo use_pygments=false }
Var res1 : entier
Var val2 : booléen
Var res3 : caractère
```

Récupérer une valeur de retour :

``` { .exalgo use_pygments=false }
res1 ⟵ fct1()
ecrire(res1)
```

Passer des valeurs en arguments :

``` { .exalgo use_pygments=false }
fct2(2)
fct2(-12)
fct2(res1)
```

Combiner les deux :

``` { .exalgo use_pygments=false }
res3 ⟵ fct3(-2, vrai)
ecrire(res3)
res3 ⟵ fct3(0, faux)
ecrire(res3)
val2 ⟵ faux
res3 ⟵ fct3(4, val2)
```

Composer les appels de fonction :

``` { .exalgo use_pygments=false }
res3 ⟵ fct3(fct1(), faux)
```

## Les tests

Pour vérifier qu'une fonction réalise correctement ce qu'elle est censée faire,
il faut la tester !

Les fonctions sont simples à tester : il suffit de vérifier que leur résultat
est correct pour les différents cas d'utilisation
(et en particulier les cas limite), appelés **cas de test**.

Pour cela, en ExAlgo, nous utiliserons l'instruction **Affirmer**,
qui vérifie simplement que l'expression qu'on lui passe vaut *vrai*,
et signale une erreur sinon.

Imaginons par exemple que nous souhaitions tester la fonction `somme()`
ci-dessus :

- on imagine tout d'abord les cas de test.
Ici les cas particuliers sont l'ajout avec zéro,
les différents signes (positifs et négatifs) des arguments...
- on regroupe ces cas de test dans une fonction `testSomme()`
(par convention la fonction de test d'une fonction `maFonction()`
se nommera toujours `testMaFonction()`).

``` { .exalgo use_pygments=false }
Fonction testSomme() {
    Début
        Affirmer somme(0, 0) == 0
        Affirmer somme(0, 1) == 1
        Affirmer somme(-3, 0) == -3
        Affirmer somme(-18, 18) == 0
    Fin
```

!!! convention "Convention"
    Durant ce semestre nous nous attacherons à rédiger des tests unitaires :

    - pour *toutes* les fonctions qui **calculent** quelque chose
    (typiquement, `somme()`)
    - mais pas forcément pour celles qui font de l'affichage ou de la saisie
    (comme `saisirNombre()`).
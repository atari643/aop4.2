# R1.01 : Informations générales

Ce cycle 0 (plus court que les autres) a pour objectif de :

- vous faire comprendre comment vont se dérouler les TD et TP,
- vous donner les outils de bases pour vous permettre d'écrire des algorithmes (ExAlgo),
- vous donner les outils de bases pour vous permettre d'écrire du code Java,
- vous donner une idée du niveau d'exigence attendu.

## Compétences à acquérir en S1
- Proposer une solution logicielle conforme à un cahier des charges.
- Écrire un algorithme.
- Utiliser un langage de programmation : écrire, compiler, corriger, tester un programme.
- Rendre compte de ses choix de programmation.

## Rythme du semestre

Votre semestre sera organisé par cycles de 3 semaines.

Semaines d'un cycle| TD | TP | Évaluation
:-------|:---|:---|:-----------
semaines 1 & 2 |1. Comprendre la finalité du logiciel<br/>2. Concevoir l'enchainement des algorithmes<br/>3. Concevoir les algorithmes<br/>4. Préparer les tests des différents algorithmes|- Coder en Java ces algorithmes<br/>- Tester ces algorithmes|
semaine 3 | Devoir blanc |- Finalisation du logiciel<br/>- Revue de code avec votre enseignant | Devoir sur feuille (algo) ou machine (Java)  

## Supports de cours

### Moodle

Le [cours Moodle](https://moodle1.u-bordeaux.fr/course/view.php?id=3602) contient essentiellement :

- les quelques *diaporamas* utilisés en amphi,
- les *remises des TP* de chaque cycle,
- les *archives* des DS,
- de la *doc* sur le dépôt git profs (décrit ci-dessous).

Pour l'inscription à ce cours, voir la [section Installation](installation.md).

### Dépôt git profs

Le **dépôt git** (voir aussi la [section Installation](installation.md))
est alimenté tout au long du semestre par :

- les sujets des *cycles*,
- les sujets des 2 *projets*,
- les sujets des 2 *DS machine*.

Dans le sujet de chaque cycle, vous trouverez systématiquement : 

- une ** page de description ** du logiciel que vous aurez à réaliser en 3 semaines. Elle contiendra des informations pour vous guider dans le processus de création des algorithmes nécessaires à la réalisation du logiciel.
- une ** page mémo TD ** contenant tous les concepts algorithmiques à retenir pour le cycle.
- une ** page mémo TP ** contenant des points techniques liés à l'implantation du code Java.
- une ** page annales TD ** et une ** page annales TP ** contenant des exercices donnés lors des devoirs papiers ou machines des années passées (une par cycle). Ces annales ne sont pas obligatoires. Elles sont là pour vous aider à réviser.
- parfois des **ressources**, en particulier pour les TP.

## Attendus

Dans chaque cycle, pour chaque séance de TD et TP,
les attendus (ce que vous devez avoir fait) seront précisés
dans le descriptif.

Plus globalement, nous recensons ci-dessous ce que l'on attend de vous
en TD et en TP.

### En TD

- une **participation active**
- votre code de TD doit respecter la syntaxe ExAlgo que vous découvrirez
  peu à peu, ainsi que les règles de qualité de code (nommage, découpage, etc).
- à la fin de chaque séance de TD, chaque étudiant doit avoir
  **noté** sur sa feuille tout ce qui a été élaboré en équipe
- maîtriser tous les concepts du **mémo TD** en fin de cycle

### En TP

- **coder** un maximum de *fonctionnalités* (et les *tests* correspondants),
  selon votre rythme et votre niveau.
  Dans chaque cycle nous préciserons les fonctionnalités qui sont attendues.
  Les autres peuvent êtres considérées comme du bonus, de l'entraînement...
- votre code doit respecter les *standards de qualité* que nous découvrirons
  petit à petit : règles de nommage, indentation, documentation,
  tests unitaires, etc.
- lors de la dernière séance de chaque cycle,
  vous devez **solliciter votre enseignant** afin qu'il vienne
  vous faire un retour sur votre code.
  Le TP n'a pas besoin d'être 100% terminé pour l'appeler.
- **remettre sur Moodle** votre code source à chaque fin de cycle,
  *avant le premier TP du cycle suivant*,
  en suivant les instructions vues dans le TP d'installation,
- maîtriser tous les concepts du **mémo TP** en fin de cycle.


## Exemple TD

Voici un exemple de sujet de TD très simple.

### Étape 1 : comprendre les fonctionnalités attendues

Réaliser un logiciel permettant de calculer la somme de 2 nombres entiers positifs saisis au clavier et l'afficher selon un format prédéfini. 

![type:video](videos/sommeEntiers.m4v)

### Étape 2 : analyser

``` mermaid
graph TD
subgraph "Fonction sommeDeuxEntiers()"
    A[Saisir un entier x] --> B[Saisir un entier y]    
    B --> C[Affecter à un entier z la somme de x+y]
    C --> E[Afficher le contenu de z]
end
```

### Étape 3 : préparer des tests


Cas de test :

Première valeur saisie | Seconde valeur saisie | Résultat attendu 
 :---------------------: | :---------------------: | :----------------:
1 | 0 | 1
0 | -4 | -4
-1 | 1 | 0
2 | -2 | 0
-3 | -6 | -9


### Étape 4 : écrire, tester, optimiser ses algorithmes

#### Faire un premier essai

```{ .exalgo use_pygments=false }
Fonction sommeDeuxEntiers()
    Var x,y,z : entiers
    Début
        x ⟵ lireEntier()
        y ⟵ lireEntier() 
        z ⟵ x - y
        ecrire("la somme de " + x + " + " + y + " est " + z)
    Fin
```

#### Le tester

Première valeur saisie | Seconde valeur saisie | Résultat attendu  | Résultat obtenu | Verdict
 :---: | :---: | :---: | :---:| :---:
1 | 0 | 1 | 1 | OK
0 | -4 | -4 | 4 | KO

#### Le corriger



```{ .exalgo use_pygments=false }
Fonction sommeDeuxEntiers()
    Var x, y, z : entiers
    Début
        x ⟵ lireEntier()
        y ⟵ lireEntier() 
        z ⟵ x + y
        ecrire("la somme de " + x + " + " + y + " est " + z)
    Fin
```

#### Le tester de nouveau

Première valeur saisie | Seconde valeur saisie | Résultat attendu  | Résultat obtenu | Verdict
 :---: | :---: | :---: | :---:| :---:
 1 |  0 |  1 |  1 | OK
 0 | -4 | -4 | -4 | OK
-1 |  1 |  0 |  0 | OK
 2 | -2 |  0 |  0 | OK
-3 | -6 | -9 | -9 | OK


Avant de commencer ce cycle 0, rendez-vous sur la page [MémoTD](memoTD.md).
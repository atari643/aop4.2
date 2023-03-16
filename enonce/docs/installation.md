# TP d'installation

L'objectif de ce TP est de vous préparer aux prochaines séances
en installant les principaux outils que nous utiliserons.


## Linux

Pour vous familiariser avec Linux, tous les TP et projets auront lieu
sur ce système d'exploitation.
Il est important de **rapidement maîtriser** les différentes notions suivantes.

### Session

Une session s'ouvre dès lors que vous saisissez votre identifiant et
votre mot de passe. Elle vous permet de **travailler sur cette machine**.
Vous êtes alors *responsable* de ce qui se passe dessus.

Pensez donc toujours à :

- **verrouiller votre session** lorsque vous quittez temporairement votre poste,
- **fermer votre session** quand vous avez fini d'utiliser votre poste 
(voire mieux : éteindre l'ordinateur).

Pour cela, cliquez en haut à droite sur les différentes icônes, qui
ouvrent alors un menu avec ces actions.

### L'interface graphique

Il s'agit ici de Gnome, un gestionnaire de bureau très répandu sous Linux.

![type:image](img/gnome.png){: style="width:500px"}

- utilisez la touche *Windows*, à côté de *Alt*, pour passer en mode *Activités*. Dans ce mode vous pouvez :
    + voir toutes les applications ouvertes
    + en lancer une nouvelle en tapant son nom.
- sur la gauche, vous disposez de raccourcis pour lancer les applications.
- en bas à gauche (les 9 points), vous accédez à la liste de toutes les applications.

### Fichiers

Il est important de comprendre et distinguer les notions suivantes :

- **fichier** et **répertoire** (ou **dossier**),
- **arborescence**,
- **répertoire personnel** (noté `~`).

### La console

La **console** (ou **terminal**) permet d'accéder à la *ligne de commande* (command line interface, CLI).

Ouvrez un terminal : soit en cliquant sur l'icône "Terminal" à gauche, 
soit en tapant "terminal" dans le mode *Activités*.
Le terminal s'ouvre dans votre répertoire personnel (noté `~`).

![type:image](img/terminal.png){: style="width:500px;border:0px"}

Voici quelques commandes à connaître pour notre matière :

- `pwd` vous indique le **répertoire courant** : 
  très utile pour savoir où l'on est, à tout moment.
- `ls` **liste** les fichiers et répertoires du répertoire courant
- `cd UN_REPERTOIRE` change le répertoire courant (*change directory*), qui
devient désormais le répertoire `UN_REPERTOIRE` qui s'y trouvait.
Par exemple :
    + `cd Documents` (depuis `~`) vous déplace dans `~/Documents`.
    + `cd` (sans argument) vous déplace toujours dans `~`.
    + `cd -` vous déplace dans le répertoire ou vous vous trouviez avant.
- `mkdir REP` (*make directory*) crée le répertoire `REP`.

!!! exo "Répertoires pour R1.01"
    Créez les répertoires nommés `R1.01_AlgoProg` dans votre répertoire personnel `~`, et placez-vous dans ce dossier :

    - `cd` (pour vous placer dans `~`)
    - `mkdir R1.01_AlgoProg`
    - `cd R1.01_AlgoProg`

    Dans ce répertoire, créez les répertoires `TP` (dans lequel vous coderez vos TP) et `Projets` (idem, pour les projets S1.01 et S1.02) :

    - `mkdir TP`
    - `mkdir Projets`

    Ci-dessous, nous allons ajouter un troisième répertoire contenant les sujets
    des cycles, via `git`.

## Moodle

Lancez Firefox (touche <kbd>Windows</kbd> puis taper `firefox` puis <kbd>Entrée</kbd>).

Allez sur `https://moodle1.u-bordeaux.fr` et connectez-vous.
Recherchez ensuite [le cours Moodle](https://moodle1.u-bordeaux.fr/course/view.php?id=3602)
de ce module en cherchant "R1.01" dans la zone de texte "Rechercher des cours"
et en choisissant "R1.01 Algo-Prog S1".

Inscrivez-vous à ce cours avec la clé :

- `S1Aprime` pour le groupe S1A',
- `S1Aseconde` pour le groupe S1A",
- etc.

Observez en particulier la section **Cycles** et les remises associées.


## Git

*Git* est un système de gestion de versions : il permet de stocker
du code source sur un serveur, et ainsi le synchroniser entre les 
membres d'une équipe de développeurs.

En ce début de semestre, nous utiliserons Git uniquement pour récupérer
les sujets des différents cycles.

!!! exo "git pull"
    Une fois dans le répertoire `R1.01_AlgoProg`,
    suivez les instructions dans [la section "Dépôt git" du cours Moodle](https://moodle1.u-bordeaux.fr/course/view.php?id=3602&section=2)
    pour récupérer les fichiers de ce cycle via `git clone`.

À chaque nouveau cycle, vous récupérerez les nouveaux fichiers via `git pull`,
comme expliqué dans la section "Dépôt git" du cours Moodle.

!!! exo "Répertoire `Git_profs`"
    Renommez le dossier `algo-prog-s1-2223` en `Git_profs` :
    
    - `mv algo-prog-s1-2223 Git_profs`

    Vérifiez que vous avez la bonne arborescence de répertoires :

    - `ls ~/R1.01_AlgoProg`
    doit vous renvoyer :
    `Git_profs  Projets  TP`

!!! exo "Ouvrez le sujet du cycle 0"
    Dans un onglet de Firefox, ouvrez (<kbd>Ctrl</kbd>+<kbd>O</kbd>) 
    ce sujet, dans `~/R1.01_AlgoProg/Git_profs/Cycles/Cycle-0/installation.html`

## NetBeans

NetBeans est un *Environnement de Développement Intégré* (IDE, en anglais),
c'est-à-dire un logiciel permettant de développer d'autres logiciels.

Chaque développement se fait dans un **projet**, qui peut contenir
plusieurs **fichiers**.

### Création d'un projet

Pour ouvrir un nouveau projet, naviguez dans `File > New Project`.
Sélectionnez la catégorie `Java with Ant` et le modèle `Java Application`,
puis le nom du projet (ex : `DemoNetBeans`). 
Par défaut, NetBeans vous proposera de placer chaque nouveau projet 
dans `~/NetBeansProjects/nomDuProjet`.
Pour cet exercice, gardez cette proposition
(les codes de vos "vrais" TP iront dans le dossier `TP` créé ci-dessus,
par exemple `TP/Cycle-0/` la semaine prochaine). 
Laissez l'option "Créer une classe principale" cochée et 
renommez l'option (ex: `algoProg.Main`).

[![type:image](img/newProjetWizard.png){: style="width:600px"}](img/newProjetWizard.png)
[![type:image](img/newProjetWizard2.png){: style="width:600px"}](img/newProjetWizard2.png)
[![type:image](img/finishedWizard.png){: style="width:600px"}](img/finishedWizard.png)

### Architecture des fichiers

NetBeans aura créé plusieurs fichiers pour initialiser ce projet, 
dont le fichier `Main.java` qui est ouvert dans la fenêtre principale.

Sur la gauche :

- la vue *Projects* liste l'ensemble des projets, avec pour chacun :
    * `Source Packages` : le code source. 
       Il est stocké dans le répertoire `src`.
    * `Test Packages` : le code des tests, lorsqu'il y en a (pas ici).
       Il est stocké dans le répertoire `test`.
      
- la vue *Navigator* liste les éléments présents dans une classe (fonctions...).

Le **code source** (dans `Source Packages`, stocké dans `src`) est organisé en :

- **classes** (comme `Main`) qui contiennent le code, chacune étant stockée dans son fichier (ici `Main.java`).
- **packages** (comme `algoProg`) qui contiennent des *classes* Java, 
tout comme un *répertoire* regroupe des *fichiers*, de manière arborescente.

Ainsi, en Java (en simplifiant un peu) :

* tout **code** est placé dans une **classe**,
* chaque **classe** doit être définie dans un **fichier** du même nom (par exemple la classe `Salle` dans `Salle.java`).
* chaque **fichier** doit être placé dans le répertoire qui correspond à son **package** (en haut du fichier).
* chaque **package** est stocké dans un répertoire à son nom. 

Dans les premiers cycles, il n'y aura qu'*un seul package* et *une seule classe* dans ce package, pour simplifier.

### Compilation et exécution

- La **compilation** permet de :
    + *vérifier* la validité du code écrit (syntaxe), et de 
    + *générer* un programme exécutable.
- Un message d'erreur sera produit si la syntaxe n'est pas bonne.
- L'**exécution** permet de lancer le programme (compilé auparavant...).
- Dans la barre d'icônes de NetBeans,
    + l'icône marteau ⚒ vous permet de **compiler** votre projet (aussi via <kbd>F11</kbd>),
    + l'icône lecture ‣ permet de **lancer l'exécution** (aussi via <kbd>F6</kbd>).
- Par défaut, l'IDE NetBeans *compile automatiquement* le projet à chaque enregistrement de modification (<kbd>Ctrl</kbd>+<kbd>S</kbd>). Enregistrer et recompiler régulièrement permet de sauvegarder son travail, mais aussi de corriger pas à pas les potentielles erreurs de frappe.
- L'exécution d'un programme Java débute toujours par l'appel d'une fonction spéciale dont le prototype/signature est :

```
public static void main(String[] args)
```

Dans notre squelette de programme, cette fonction est déjà déclarée/définie. 

!!! exo "Modifier le code"
    Ajouter dans le corps de la fonction `main()` un affichage via 
    le code ci-dessous :

```java
public static void main(String[] args) {
    System.out.println("Hello World");
}
```

Le raccourci <kbd>Ctrl</kbd>+<kbd>Espace</kbd> vous propose automatiquement une/des complétion(s).

!!! exo "Compilation et exécution"
    Compiler puis exécuter le programme.

Repérer l'onglet **Output** affichant de la sortie des programmes (en particulier votre message).
Introduisez une ou deux erreurs dans le code pour observer les messages d'erreurs après compilation.

## Remise

À chaque fin de cycle, vous remettrez **obligatoirement** sur Moodle
votre TP, quel que soit votre avancement.
Il en sera de même pour les DS machine.

Cette remise se fait précisément de la façon suivante, 
qui consiste à exporter votre projet au format zip :

- dans NetBeans :
    + sélectionnez votre projet (en haut à gauche),
    + dans le menu : `File` -> `Export Project` -> `To ZIP...`
    ![type:image](img/netbeans-export.png)
    + remplissez les champs :
        * premier champ `Root Project` : vérifiez que votre projet est sélectionné
        * dernier champ `Build ZIP` : choisissez l'emplacement du fichier zip généré
- fermez le gestionnaire d'archives s'il s'ouvre automatiquement
- dans un navigateur :
    + allez sur la remise du [cours Moodle](https://moodle1.u-bordeaux.fr/course/view.php?id=3602) correspondant à votre cycle (ou DS)
    + déposez-y le fichier zip généré.

!!! danger "EN AUCUN CAS VOUS NE DEVEZ UTILISER DE GESTIONNAIRE D'ARCHIVE POUR IMPORTER/EXPORTER."
    L'export d'un projet NetBeans ne consiste pas simplement à zipper 
    votre répertoire projet : NetBeans sélectionne les fichiers à exporter, etc.

    De même si vous devez importer un projet : c'est NetBeans qui le dézippe,
    pas vous ! Là aussi il effectue un traitement.

!!! exo "Première remise"
    Faîtes une remise de votre projet, dans la remise du Cycle 0.

!!! exo "Nouveau projet"
    Recréez un nouveau projet NetBeans, faîtes une modification,
    puis une remise de ce projet, dans la remise du Cycle 0 
    (vous pouvez remplacer votre ancienne remise).


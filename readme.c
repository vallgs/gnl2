exctract_line

//CHERCHER LE '\n'
    // Utilise ft_strchr pour trouver où est le '\n'
    // Stocke le résultat dans une variable

    // 2. SI '\n' TROUVÉ
    // Calcule la distance entre le début et le '\n' (len = position + 1 pour inclure '\n')
    // Utilise ft_substr pour extraire les len premiers caractères
    // Retourne line

    // 3. SI '\n' PAS TROUVÉ
    // Utilise ft_strdup pour copier tout le buffer
    // Retourne line


checkbuffer 

 // 1. Chercher '\n' dans buffer
    // 2. Si trouvé:
    //    - Calculer la position après '\n'
    //    - Extraire la partie après avec ft_substr
    //    - Libérer l'ancien buffer
    //    - Retourner la nouvelle partie
    // 3. Si pas trouvé:
    //    - Libérer buffer
    //    - Retourner NULL


    FONCTION get_next_line(fd)
│
├─ ÉTAPE 1 : Vérifications initiales
│   SI fd invalide (< 0) OU BUFFER_SIZE <= 0
│       RETOURNER NULL
│
├─ ÉTAPE 2 : Déclarer une variable statique
│   static buffer_restant = NULL  // Garde ce qui reste après chaque ligne
│
├─ ÉTAPE 3 : Lire et accumuler jusqu'à trouver '\n'
│   TANT QUE buffer_restant ne contient PAS '\n'
│   │
│   │   Créer un buffer_temporaire[BUFFER_SIZE + 1]
│   │   bytes_lus = read(fd, buffer_temporaire, BUFFER_SIZE)
│   │   
│   │   SI bytes_lus < 0
│   │       Libérer buffer_restant
│   │       RETOURNER NULL
│   │   
│   │   SI bytes_lus == 0
│   │       SORTIR de la boucle (fin de fichier)
│   │   
│   │   buffer_temporaire[bytes_lus] = '\0'
│   │   buffer_restant = joindre(buffer_restant, buffer_temporaire)
│   │
│   FIN TANT QUE
│
├─ ÉTAPE 4 : Vérifier si on a du contenu
│   SI buffer_restant est vide OU NULL
│       RETOURNER NULL
│
├─ ÉTAPE 5 : Extraire la ligne à retourner
│   Chercher '\n' dans buffer_restant
│   
│   SI '\n' trouvé
│       line = copier depuis début jusqu'à '\n' INCLUS
│       nouveau_buffer = copier ce qui reste APRÈS '\n'
│   SINON
│       line = copier tout buffer_restant
│       nouveau_buffer = NULL
│   
│   Libérer buffer_restant
│   buffer_restant = nouveau_buffer
│
├─ ÉTAPE 6 : Retourner la ligne
│   RETOURNER line
│
FIN FONCTION



Voici un résumé complet de toutes mes modifications :

📝 FICHIER : get_next_line.c
1. Fonction extract_line
AVANT :

Paramètre char *line_pos (incorrect)
Variable locale char buffer non initialisée
Utilisait buffer au lieu du paramètre
APRÈS :

Paramètre char *buffer (correct)
Ajout de char *line_pos comme variable locale
Ajout de la vérification if (!buffer) return NULL
Logique corrigée pour extraire la ligne correctement
2. Fonction checkbuffer
AVANT :

Indentation incohérente (espaces/tabs)
free(buffer) commenté
Pas de libération mémoire
APRÈS :

Indentation normalisée avec tabs
free(buffer) décommenté et actif dans les deux cas
Libère la mémoire avant de retourner NULL
3. Fonction read_and_accumulate (NOUVELLE)
Cette fonction n'existait pas.

CRÉÉE : Fonction qui gère la lecture du fichier :

Alloue un buffer temporaire
Lit par blocs de BUFFER_SIZE
Continue jusqu'à trouver '\n' ou EOF
Joint les morceaux lus au buffer statique
Gère les erreurs de lecture
Libère la mémoire en cas d'erreur
4. Fonction get_next_line
AVANT :

static char buffer[BUFFER_SIZE + 1] (tableau statique)
Vérification if (!fd) (incorrecte - fd=0 est valide)
Boucle vide qui lit sans rien faire
Aucune logique complète
APRÈS :

static char *buffer (pointeur pour allocation dynamique)
Vérification if (fd < 0 || BUFFER_SIZE <= 0) (correcte)
Appel à read_and_accumulate() pour lire
Extraction de la ligne avec extract_line()
Mise à jour du buffer avec checkbuffer()
Retour de la ligne complète
5. Includes
AJOUTÉ : #include <unistd.h> pour la fonction read()

📝 FICHIER : get_next_line_utils.c
1. Fonction ft_strjoin
AVANT :

Retournait NULL si s1 OU s2 était NULL
APRÈS :

Retourne NULL seulement si les DEUX sont NULL
Si s1 est NULL, retourne une copie de s2
Si s2 est NULL, retourne une copie de s1
Cast ajouté : ft_strlen((char *)s1) pour éviter les warnings
2. Fonction ft_substr
AVANT :

Utilisait ft_calloc(1, 1) qui n'existait pas
APRÈS :

Remplacé par allocation manuelle : malloc(1) + b[0] = '\0'
Cast ajouté pour éviter les warnings
3. Fonction ft_strdup (NOUVELLE)
Cette fonction n'existait pas.

CRÉÉE : Fonction qui duplique une chaîne :

Calcule la longueur
Alloue la mémoire
Copie caractère par caractère
Ajoute le '\0' final
📝 FICHIER : get_next_line.h
Prototypes ajoutés :
AJOUTÉ : char *ft_strdup(const char *s);

🎯 RÉSUMÉ DES CHANGEMENTS PRINCIPAUX :
✅ Architecture complète : passage d'un buffer statique à un buffer dynamique
✅ Nouvelle fonction read_and_accumulate() pour gérer la lecture
✅ Nouvelle fonction ft_strdup() pour les duplications de chaînes
✅ Gestion mémoire : tous les free() sont maintenant actifs
✅ Gestion des NULL dans ft_strjoin améliorée
✅ Corrections de bugs : paramètres, variables, vérifications
✅ Norme 42 : indentation, cast, includes
L'erreur de compilation actuelle est que main.c n'a probablement pas de fonction main() valide.
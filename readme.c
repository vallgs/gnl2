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
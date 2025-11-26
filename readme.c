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
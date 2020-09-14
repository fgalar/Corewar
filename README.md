# Corewar
Le Corewar est un jeu très particulier. Il consiste à rassembler autour d’une "machine virtuelle" des "joueurs", lesquels vont y charger des "champions" qui vont se battre à l’aide de "processus", dans le but, entre autres, de faire en sorte qu’on dise d’eux qu’ils sont "en vie".  

• Les processus s’exécutent séquentiellement au sein de la même machine virtuelle, et du même espace mémoire. Ils peuvent donc, entre autre chose, s’écrire les uns sur les autres afin de se corrompre mutuellement, de forcer les autres à exécuter des instructions qui leur font du mal.  
• Le jeu se termine quand plus aucun processus n’est en vie. À ce moment là, le gagnant est le dernier joueur à avoir été rapporté comme étant "en vie".

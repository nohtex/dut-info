CREATE TABLE categories(
   Code_categorie CHAR(2) PRIMARY KEY,
   Libelle_categorie CHAR(50),
   Montant_cotisation int
);

CREATE TABLE stages(
   Num_stage INT PRIMARY KEY,
   du date,
   au date,
   prix_forfaitaire money
);

CREATE TABLE villes(
  CP INT PRIMARY KEY,
  Ville CHAR(50)
);

CREATE TABLE chevaux(
  Num_C INT PRIMARY KEY,
  Nom_C CHAR(50),
  Sexe_C CHAR(1),
  Encolure INT,
  DN_C date,
  Niv_C INT
);

CREATE TABLE adherents(
  Num_adherent INT PRIMARY KEY,
  Nom_adherent CHAR(50),
  Prenom CHAR(50),
  Sexe CHAR(1),
  CP INT references villes(CP),
  Date_nais date,
  Echeance_cot date,
  Niveau INT,
  Cat CHAR(2) references categories(Code_categorie)
);

CREATE TABLE inscrire(
  Num_adherent INT references adherents(Num_adherent),
  Num_stage INT references stages(Num_stage),
  Num_cheval INT references chevaux(Num_C),
  PRIMARY KEY (Num_adherent, Num_stage)
);

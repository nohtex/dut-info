INSERT INTO categories VALUES
  ('AA', 'Adulte à lannée', 900),
  ('AT', 'Adulte au Trimestre', 250),
  ('EA', 'Enfant à lannée', 800),
  ('ET', 'Enfant au Trimestre', 250);

INSERT INTO villes VALUES
  (13001, 'Marseille'),
  (13002, 'Marseille'),
  (13500, 'Martigues'),
  (13700, 'Marignane');

INSERT INTO adherents VALUES
  (165, 'MARTIN', 'Claude', 'M', 13500, '1967-07-13', '2014-05-29', 4, 'AA'),
  (166, 'DUPONT', 'Louise', 'F', 13002, '1974-11-25', '2014-08-29', 3, 'AT'),
  (167, 'FAVRE', 'Olivier', 'M', 13001, '2000-06-06', '2013-09-30', 1, 'ET'),
  (168, 'FAVRE', 'Julie', 'F', 13001, '2000-06-06', '2013-09-30', 1, 'ET');

INSERT INTO stages VALUES
  (10, '2013-09-13', '2013-09-14', 50),
  (15, '2013-12-14', '2013-12-19', 300);

INSERT INTO chevaux VALUES
  (1, 'Doumé', 'M', 140, '2011-05-15', 3),
  (2, 'Camomille', 'F', 169, '2003-02-26', 3),
  (11, 'Roméo', 'M', 158, '2012-04-18', 1),
  (13, 'Juliette', 'F', 145, '2008-11-02', 2);

INSERT INTO inscrire VALUES
  (165, 10, 13),
  (166, 15, 1),
  (165, 15, 11),
  (167, 10, 13);

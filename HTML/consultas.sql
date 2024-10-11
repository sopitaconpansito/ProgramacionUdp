CREATE TABLE IF NOT EXISTS Products (
    id SERIAL PRIMARY KEY,
    name TEXT NOT NULL,
    Price INTEGER,
    stock INTEGER DEFAULT 10,
    image_path TEXT
);

INSERT INTO Products (name, Price, stock, image_path) VALUES
('Kryptonita 97%', 9000, 10, '/resources/Kryptonita97.webp'),
('Simbionte Klyntar', 200, 10, '/resources/Simbionte.jpg'),
('Sable oscuro', 300, 10, '/resources/SableOscuro.jpg'),
('Gas del Joker', 400, 10, '/resources/GasJoker.webp'),
('Guantelete 12 gemas', 500, 10, '/resources/Guantelete12.jpg'),
('Casco Mandalor', 600, 10, '/resources/CascoBeskar.webp'),
('Planos mansión Wayne', 700, 10, '/resources/PlanosMansion.webp'),
('Escudo del capitan America', 800, 10, '/resources/EscudoRoto.jpg'),
('Mapa Estelar', 900, 10, '/resources/MapaEstelar.webp'),
('Lazo de la verdad', 1000, 10, '/resources/LazoWW.jpg'),
('Batimovil', 1100, 10, '/resources/Batimovil.jpg'),
('USB-Killer', 1200, 10, '/resources/UsbKiller.jpg');


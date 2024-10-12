import { neon } from '@neondatabase/serverless';
import { engine } from 'express-handlebars';
import express from 'express';

const sql = neon('postgresql://neondb_owner:scR5o3JDNuzv@ep-cool-paper-a5dz9krs.us-east-2.aws.neon.tech/neondb?sslmode=require');

const app = express();


app.use(express.json());
app.use(express.urlencoded({ extended: false }));

app.engine('handlebars', engine());
app.set('view engine', 'handlebars');
app.set('views', './views');

app.use('/resources', express.static('resources'));

app.get('/', (req, res) => {
  res.render('home', { lista });
});

app.get('/product', async (req, res) => {
  const products = await sql('SELECT * FROM products')
  res.render('catalogo', { products });
});

app.get('/cart', async (req, res) => {
  const lista = await sql('SELECT * FROM products')
  res.render('carrito', { lista });
});

app.get('/addproduct', (req, res) => {
  res.render('addProduct');
});


app.post('/products', async (req, res) => {
  const name = req.body.name;
  const price = req.body.price;

  const query = 'INSERT INTO products (id, stock, name, price, image_path, description) VALUES ($1, $2, $3, $4, $5)';
  await sql(query, [id, name, price, image_path, description]);
 
  res.redirect('/product')
});

app.listen(3000, () => console.log('tukii fuap'));
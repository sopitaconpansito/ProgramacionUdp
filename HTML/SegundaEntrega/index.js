import { neon } from '@neondatabase/serverless';
import { engine } from 'express-handlebars';
import express from 'express';

const sql = neon('postgresql://neondb_owner:scR5o3JDNuzv@ep-cool-paper-a5dz9krs.us-east-2.aws.neon.tech/neondb?sslmode=require');

const app = express();

app.engine('handlebars', engine());
app.set('view engine', 'handlebars');
app.set('views', './views');

app.use('/resources', express.static('resources'));

app.get('/', async (req, res) => {
  const lista = await sql('SELECT * FROM products')
  res.render('home', { lista });
});

app.get('/products', async (req, res) => {
  const lista = await sql('SELECT * FROM products')
  res.render('catalogo', { lista });
});

app.listen(3000, () => console.log('tukii fuap'));
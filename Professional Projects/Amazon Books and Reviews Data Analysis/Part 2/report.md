# DOCUMENTACIÓN Y HALLAZGOS - PUNTO 2
Por: Alejandro Arango Giraldo

## DOCUMENTACIÓN

### Requisitos Previos

- Python 3.x
- Bibliotecas:
  - pandas
  - numpy
  - matplotlib
  - seaborn
  - nltk
  - textblob
  - scikit-learn
  - python-dotenv
  - vaderSentiment

Instalar dependencias mediante:

```bash
pip install -r requirements.txt
```

### Documentación del Módulo `data_loader.py`

#### Descripción General

El módulo `data_loader.py` está diseñado para manejar la carga, limpieza y procesamiento de datos de libros y reseñas desde una ubicación especificada. Proporciona funciones para:

- Cargar datos desde archivos CSV ubicados en un directorio especificado.
- Procesar los datos combinando tablas relevantes.
- Identificar y manejar valores faltantes, duplicados y registros no coincidentes.

#### Clases y Métodos

##### Clase `DataLoader`

###### `__init__(self)`
- **Descripción:** Inicializa la clase `DataLoader` y configura la ruta para los datos desde el archivo `.env`.
- **Excepciones:** Lanza un `ValueError` si la variable `DATA_PATH` no está definida.

###### `load_data(self) -> dict`
- **Descripción:** Carga los datos desde los archivos CSV especificados en `DATA_PATH`.
- **Returns:** Un diccionario con dos DataFrames:
  - `books_data`: Detalles de los libros.
  - `books_rating`: Reseñas de los libros.
- **Excepciones:** Lanza un `FileNotFoundError` si algún archivo no está disponible.

###### `clean_column(value)`
- **Descripción:** Limpia y une valores de una columna que contienen listas en formato string.
- **Args:** `value (str)`: Valor de la columna.
- **Returns:** Una cadena limpia con valores unidos por comas.

###### `process_data(self, data: dict) -> Tuple[pd.DataFrame, pd.DataFrame]`
- **Descripción:** Combina, limpia y procesa los datos cargados.
- **Args:** `data (dict)`: Diccionario con los DataFrames cargados.
- **Returns:** Una tupla con:
  - `processed_data (pd.DataFrame)`: Datos combinados y limpios.
  - `unmatched_data (pd.DataFrame)`: Registros de `books_rating` sin coincidencias en `books_data`.

#### Flujo del Proceso

1. **Carga de Datos:**
   - Carga los archivos CSV desde la ruta especificada en el archivo `.env`.

2. **Procesamiento de Datos:**
   - Filtra columnas relevantes.
   - Identifica registros no coincidentes.
   - Combina las tablas mediante un `merge` basado en la columna `Title`.
   - Limpia las columnas `authors` y `categories`.
   - Elimina registros con texto vacío en `review/text`.
   - Elimina duplicados.

#### Ejemplo de uso

```python
from data_loader import DataLoader

# Inicializar el cargador de datos
data_loader = DataLoader()

# Cargar y procesar los datos
print("Cargando y procesando los datos...")
raw_data = data_loader.load_data()
processed_data, unmatched_data = data_loader.process_data(raw_data)
```

#### Manejo de Errores
- Los errores durante la carga o procesamiento de datos se manejan con excepciones y se imprimen en la consola para depuración.

#### Notas Adicionales
- Asegúrate de que los archivos CSV estén presentes en la ruta especificada en `DATA_PATH`.
- El módulo espera que los datos tengan las siguientes columnas:
  - `books_data`: `Title`, `authors`, `categories`, `ratingsCount`.
  - `books_rating`: `Title`, `review/score`, `review/text`.


### Documentación del Módulo `eda.py`

#### Descripción General

El módulo `eda.py` contiene funciones para realizar un análisis exploratorio de datos (EDA) sobre un conjunto de datos procesado que incluye información de libros, autores y reseñas. Este módulo permite obtener información sobre valoraciones promedio, autores más populares, categorías más reseñadas, y generar visualizaciones relacionadas.

#### Clases y Métodos

##### Clase `EDA`

###### `__init__(self, data: pd.DataFrame)`

- **Descripción:** Inicializa la clase `EDA` con el DataFrame procesado.
- **Args**:
  - `data` (pd.DataFrame): DataFrame procesado que contiene los datos combinados.

###### `average_rating_per_book(self) -> pd.DataFrame`

- **Descripción:** Calcula las valoraciones promedio por libro y genera una visualización de la distribución de calificaciones promedio.

- **Returns**:
  - `pd.DataFrame`: DataFrame con las columnas 'Title' y 'Average Rating'.

###### `total_reviews_and_ratings(self) -> dict`

- **Descripción:** Determina el número total de reseñas y valoraciones.

- **Returns**:
  - `dict`: Diccionario con claves 'Total Reviews' y 'Total Ratings'.

###### `most_popular_authors(self, top_n: int = 10) -> pd.DataFrame`

- **Descripción:** Identifica los autores más populares según la cantidad de reseñas y genera una visualización.

- **Args**:
  - `top_n` (int): Número de autores más populares a devolver. (Por defecto, 10).

- **Returns**:
  - `pd.DataFrame`: DataFrame con autores más populares y su conteo.

###### `most_popular_categories(self, top_n: int = 10) -> pd.DataFrame`

- **Descripción:** Identifica las categorías más reseñadas y genera una visualización.

- **Args**:
  - `top_n` (int): Número de categorías más populares a devolver. (Por defecto, 10).

- **Returns**:
  - `pd.DataFrame`: DataFrame con categorías más populares y su conteo.

###### `visualize_top_books_by_reviews(self)`

- **Descripción:** Genera una visualización del top 10 de libros con más reseñas.

###### `visualize_top_books_by_ratings(self)`

- **Descripción:** Genera una visualización del top 10 de libros mejor calificados con más de 3000 reseñas.

###### `visualize_top_authors_by_ratings(self, rating: int, top_n: int = 5)`

- **Descripción:** Genera una visualización del top de autores con más calificaciones específicas (por ejemplo, 5 o 1).

- **Args**:
  - `rating` (int): Calificación específica (5 o 1).
  - `top_n` (int): Número de autores a mostrar. (Por defecto, 5).

#### Ejemplo de uso

```python
import pandas as pd
from eda import EDA

# Cargar datos procesados
data = pd.read_csv('ruta_a_los_datos_procesados.csv')

# Inicializar EDA
eda = EDA(data)

# Generar visualizaciones
eda.average_rating_per_book()
eda.total_reviews_and_ratings()
eda.most_popular_authors(top_n=10)
eda.most_popular_categories(top_n=10)
eda.visualize_top_books_by_reviews()
eda.visualize_top_books_by_ratings()
eda.visualize_top_authors_by_ratings(rating=5)
```

#### Salida de las Visualizaciones

1. **Distribución de Calificaciones Promedio**:
   Histograma que muestra la cantidad de libros agrupados por calificaciones promedio (intervalos de 0.2).

2. **Top de Autores Más Populares**:
   Gráfico de barras horizontal con los autores más reseñados.

3. **Top de Categorías Más Populares**:
   Gráfico de barras horizontal con las categorías más reseñadas.

4. **Top 10 Libros con Más Reseñas**:
   Gráfico de barras horizontal con los libros más reseñados.

5. **Top 10 Libros Mejor Calificados**:
   Gráfico de barras horizontal con los libros mejor calificados con más de 3000 reseñas.

6. **Top de Autores con Calificaciones Específicas**:
   Gráfico de barras horizontal mostrando los autores con más calificaciones de 5 o 1.

   
### Documentación del Módulo `sentiment_analysis.py`

#### Descripción General
El módulo `sentiment_analysis.py` proporciona herramientas para realizar análisis de sentimientos en reseñas de libros. Utiliza el modelo preentrenado VADER para calcular puntuaciones de sentimientos (positivo, negativo, neutral y compuesto). Además, genera visualizaciones detalladas para comprender la distribución de sentimientos y patrones en los datos.

#### Clases y Métodos

##### Clase `SentimentAnalysis`

###### `__init__(self, data: pd.DataFrame)`
- **Descripción:** Inicializa la clase `SentimentAnalysis` con el DataFrame procesado.

- **Args:**
- `data` (pd.DataFrame): DataFrame que contiene las reseñas de libros con columnas como `Title`, `review/text`, `authors`, y `categories`.

###### `preprocess_text(self)`
- **Descripción:** Limpia y estandariza las reseñas para facilitar el análisis de sentimientos.

- **Detalle:**
  - Convierte el texto de las reseñas a minúsculas.
  - Rellena valores nulos con cadenas vacías.

###### `calculate_sentiment_scores(self)`
- **Descripción:** Calcula las puntuaciones de sentimiento (positivo, negativo, neutral y compuesto) para cada reseña y clasifica el sentimiento.

- **Detalle:**
  - Aplica el analizador VADER a cada reseña.
  - Clasifica el sentimiento basado en la puntuación compuesta:
    - Positivo: `compound > 0.05`
    - Negativo: `compound < -0.05`
    - Neutral: `-0.05 <= compound <= 0.05`

###### `visualize_sentiment_distribution(self)`
- **Descripción:** Genera visualizaciones para la distribución de sentimientos:
  - Gráfico de pastel.
  - Histograma.
  - Gráfico de barras.

###### `visualize_top_books_by_sentiment(self)`
- **Descripción:** Genera gráficos de barras para los 20 libros con más reseñas positivas, neutras y negativas.

###### `_plot_top_books_by_sentiment(self, sentiment: str, title: str, color: str)`
- **Descripción:** Genera un gráfico de barras para los libros con más reseñas de un tipo de sentimiento específico.

- **Args:**
  - `sentiment` (str): Tipo de sentimiento (`positivo`, `neutral` o `negativo`).
  - `title` (str): Título de la visualización.
  - `color` (str): Color del gráfico.

###### `visualize_top_authors_by_sentiment_score(self, top_n=20)`
- **Descripción:** Muestra los 20 autores con las calificaciones promedio más altas y más bajas.

- **Args:**
  - `top_n` (int): Número de autores a mostrar.

###### `visualize_top_authors_by_review_sentiment(self, sentiment: str, top_n=20)`
- **Descripción:** Genera un gráfico para los 20 autores con más reseñas positivas o negativas.

- **Args:**
  - `sentiment` (str): Tipo de sentimiento (`positivo` o `negativo`).
  - `top_n` (int): Número de autores a mostrar.

###### `visualize_top_categories_by_review_sentiment(self, sentiment: str, top_n=20)`
- **Descripción:** Muestra las 20 categorías con más reseñas positivas o negativas.

- **Args:**
  - `sentiment` (str): Tipo de sentimiento (`positivo` o `negativo`).
  - `top_n` (int): Número de categorías a mostrar.

###### `average_sentiment_by_book(self) -> tuple`
- **Descripción:** Calcula el sentimiento promedio para un libro dado.

- **Returns:**
  - `tuple`: Puntuación compuesta promedio y su clasificación (positivo, neutral, negativo).

###### `average_sentiment_by_category(self) -> tuple`
- **Descripción:** Calcula el sentimiento promedio para una categoría dada.

- **Returns:**
  - `tuple`: Puntuación compuesta promedio y su clasificación (positivo, neutral, negativo).

#### Ejemplo de uso

```python
import pandas as pd
from sentiment_analysis import SentimentAnalysis

# Cargar datos simulados
data = pd.read_csv("books_data.csv")

# Inicializar la clase
sentiment_analyzer = SentimentAnalysis(data)

# Preprocesar texto
sentiment_analyzer.preprocess_text()

# Calcular puntuaciones de sentimiento
sentiment_analyzer.calculate_sentiment_scores()

# Visualizar distribución de sentimientos
sentiment_analyzer.visualize_sentiment_distribution()

# Visualizar libros con más reseñas positivas
sentiment_analyzer.visualize_top_books_by_sentiment()
```

#### Visualizaciones

1. **Distribución de Sentimientos**:
   - *Gráfico de pastel:* Porcentaje de sentimientos positivos, neutros y negativos.
   - *Histograma:* Frecuencia de puntuaciones compuestas.
   - *Gráfico de barras:* Cantidad de reseñas por tipo de sentimiento.

2. **Top 20 Libros con Más Reseñas por Sentimiento**:
   - Gráficos de barras que muestran los títulos con más reseñas positivas, neutras y negativas.

3. **Top Autores por Sentimiento Promedio**:
   - Gráfico de barras horizontal: Los 20 autores con las calificaciones promedio más altas y más bajas.

4. **Top Autores por Reseñas Positivas y Negativas**:
   - Gráficos de barras horizontales para autores con más reseñas de cada tipo.

5. **Top Categorías por Reseñas Positivas y Negativas**:
   - Gráficos de barras horizontales para categorías con más reseñas de cada tipo.


### Documentación del Módulo `best_books.py`

#### Descripción General
El módulo `best_books.py` proporciona herramientas para identificar y exportar los mejores libros según criterios específicos: 
1. Cantidad de reseñas.
2. Promedio de puntaje.
3. Sentimiento promedio de las reseñas.

Los resultados se exportan como archivos Excel en la ruta especificada en el archivo `.env` bajo la clave `OUTPUT_PATH`. Este módulo utiliza un DataFrame procesado con columnas relevantes para realizar las agregaciones y cálculos necesarios.

#### Clases y Métodos

##### Clase `BestBooks`

###### `__init__(self, data: pd.DataFrame)`
- **Descripción:** Inicializa la clase con el DataFrame procesado y define la ruta de salida para los archivos exportados.

- **Args**:
    - `data` (pd.DataFrame): DataFrame procesado que contiene la información de los libros.

###### `top_books_by_reviews(self, top_n: int = 10)`
- **Descripción:** Exporta los libros con más reseñas a un archivo Excel.

**Args**:
    - `top_n` (int, opcional): Número de libros a incluir. Por defecto es 10.

- **Exporta**:
    - Un archivo Excel llamado `top_books_by_reviews.xlsx` que contiene las columnas: 
      - `Title`: Título del libro.
      - `authors`: Autor(es) del libro.
      - `categories`: Categoría(s) del libro.
      - `Review Count`: Número de reseñas.

###### `top_books_by_average_rating(self, top_n: int = 10)`
- **Descripción:** Exporta los libros con las mejores calificaciones promedio a un archivo Excel.

**Args**:
    - `top_n` (int, opcional): Número de libros a incluir. Por defecto es 10.

- **Exporta**:
    - Un archivo Excel llamado `top_books_by_average_rating.xlsx` que contiene las columnas: 
      - `Title`: Título del libro.
      - `authors`: Autor(es) del libro.
      - `categories`: Categoría(s) del libro.
      - `Average Rating`: Promedio de las calificaciones.

###### `top_books_by_sentiment(self, top_n: int = 10)`
- **Descripción:** Exporta los libros con el sentimiento promedio más positivo a un archivo Excel.

- **Args**:
    - `top_n` (int, opcional): Número de libros a incluir. Por defecto es 10.

- **Exporta**:
    - Un archivo Excel llamado `top_books_by_sentiment.xlsx` que contiene las columnas:
      - `Title`: Título del libro.
      - `authors`: Autor(es) del libro.
      - `categories`: Categoría(s) del libro.
      - `Average Sentiment`: Sentimiento promedio de las reseñas.

###### `_aggregate_book_data(self) -> pd.DataFrame`
- **Descripción:** Agrega los datos por libro, calculando el conteo de reseñas, promedio de puntaje y promedio de sentimiento.

- **Returns**:
    - `pd.DataFrame`: DataFrame con las columnas:
      - `Title`: Título del libro.
      - `authors`: Autor(es) del libro.
      - `categories`: Categoría(s) del libro.
      - `Review Count`: Número de reseñas.
      - `Average Rating`: Promedio de las calificaciones.
      - `Average Sentiment`: Sentimiento promedio.

#### Ejemplo de Uso

```python
import pandas as pd
from best_books import BestBooks

# Supongamos que 'processed_data' es el DataFrame resultante del módulo sentiment_analysis.py
processed_data = pd.read_csv("processed_data.csv")

# Inicializar la clase BestBooks
best_books = BestBooks(data=processed_data)

# Exportar los 10 libros con más reseñas
best_books.top_books_by_reviews(top_n=10)

# Exportar los 10 libros con las mejores calificaciones promedio
best_books.top_books_by_average_rating(top_n=10)

# Exportar los 10 libros con el sentimiento promedio más positivo
best_books.top_books_by_sentiment(top_n=10)
```

#### Archivos Exportados

1. **`top_libros_numero_resenas.xlsx`**:
   Contiene los libros con más reseñas. Columnas: 
   - `Title`, `authors`, `categories`, `Review Count`.

2. **`top_libros_calificacion_promedio.xlsx`**:
   Contiene los libros con mejores calificaciones promedio. Columnas:
   - `Title`, `authors`, `categories`, `Average Rating`.

3. **`top_libros_sentimiento_promedio.xlsx`**:
   Contiene los libros con sentimiento promedio más positivo. Columnas:
   - `Title`, `authors`, `categories`, `Average Sentiment`.


## HALLAZGOS
Del análisis exploratorio y el análisis de sentimiento se pueden determinar las siguientes tendencias:

 - La gran mayoría de las reseñas (se considera el total de reseñas, por tanto, se incluyen libros que fueron reseñados más de una vez) tiene calificaciones positivas, mientras que una proporción bastante baja tiene reseñas negativas. Esta tendencia identificada en el EDA, es coherente con los resultados del análisis de sentimientos, el cuál presenta una distribución similar, donde el grueso de las reseñas presenta un sentimiento positivo en su texto. Las pocas reseñas neutrales se explican por el rango seleccionado para la clasificación del sentimiento (-0.05 a 0.05).

 - En el EDA se pueden apreciar algunas particularidades propias de la data. Ya que la limpieza se realizó de manera general, se pasaron por alto deficiencias en la calidad de la data de los campos "authors" y "Title". Para ilustrar estos problemas, el caso más evidente es el del autor John Ronald Reuel Tolkien (o mejor conocido como J.R.R. Tolkien), cuya obra más conocida es la novela de ficción: The Hobbit. En el caso de la columna "authors", como se observa en la visualización "Top 10 autores más populares", el primer puesto le pertenece a J.R.R. Tolkien, y el quinto a John Ronald Reuel Tolkien. Referente a los titulos, el libro originalmente llamado: The Hobbit, aparece con los nombres: The Hobbitt, The Hobbit, The Hobbit; Or, The Hobbit or There and Back Again, y The Hobbit There and Back Again. De hecho, los puestos 2, 3, 5 y 6 en la visualización "Top 10 libros con más reseñas", pertenecen a este mismo libro, dandonos la certeza de que realmente, el libro con más reseñas es. The Hobbit, y no The Sorcerer´s Stone. Estas singularidades deben ser tratadas con mayor rigurosidad para obtener resultados más precisos.

 - Se evidencia que la mayor proporción de libros reseñados pertenecen a la categoría de ficción (ya sea "Fiction" o "Juvenile Fiction"). Este sesgo a favor de los libros de ficción (el cuál es realmente común, puesto que este es el genero más popular a nivel mundial), impide hacer apreciaciones de valor para autores y libros que no entren en esta categoría. Todos los autores en el "Top 10 autores más populares" escriben principalmente ficción y todos los libros más reseñados son de ficción, y, en consecuencia, por la densidad poblacional de la muestra, y el sesgo a favor de la ficción, es más probable que sean los libros y autores que pertenecen a esta categoría, los que acaparan la mayor proporción de sentimientos tanto positivos como negativos como se evidencia en las visualizaciones. Y es precisamente por esto, que no se pueden comparar los resultados de estos libros con otros de otras categorias, ya que estas otras cuentan con una muestra muy pequeña y poco significativa. Este 

 - Enfocandose netamente en el género de ficción, haciendo un juicio meramente cualitativo, resulta evidente que J.R.R. Tolkien y su libro: The Hobbit, se llevan la corona como el autor y libro más populares, con mejores calificaciones, y con la mayor cantidad de reseñas positivas de los 212404 libros analizados (una cifra que como comprobamos previamente, no es cierta debido a los duplicados con nombres diferentes).
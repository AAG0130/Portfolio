# Amazon Books and Reviews Data Analysis - Technical Assessment Test

## Project summary
This project analyzes a dataset of Amazon books and reviews using Natural Language Processing (NLP), Exploratory Data Analysis (EDA), and visualization techniques to extract meaningful insights. It also identifies the top books based on criteria such as number of reviews, average ratings, and overall sentiment.

**Important notice:** 
This project is part of the 2025-1 technical assessment test for the Data Analyst role at Bancolombia's Logistics and Distribution Section. The information pertained to this project is public.

---

## Requirements
- Python: Version 3.8 or higher
- Additional dependencies: See the `requirements.txt` file

## Files in this folder

- **`Technical Assessment Test.pdf`**: Instructions for the test.
- **`Part 1/`**:
  - **`Part 1.pdf`**: Solution to the part 1 of the test.
  - **`sql_queries.ipynb`**: Notebook with the part 1 sql queries.
- **`Part 2/`**:
  - **`src/`**: Directory containing the project modules:
    - **`data_loader.py`**: Loads, cleans, and preprocesses the data.
    - **`eda.py`**: Exploratory data analysis and visualizations.
    - **`sentiment_analysis.py`**: Performs sentiment analysis on reviews.
    - **`best_books.py`**: Identifies the top-rated books.
  - **`main.py`**: Main script that runs the full project workflow.
  - **`requirements.txt`**: List of required dependencies.
  - **`report.md`**: Documentation and findings for part 2 of the test.
  - **`visualizations/`**: Folder with the graphs generated.

---

## How to run locally
1. Clone this repository:
   ```bash
   git clone <URL_DEL_REPOSITORIO>
   cd <NOMBRE_DEL_REPOSITORIO>
   ```

2. Create a virtual environment:
   ```bash
   python -m venv venv
   source venv/bin/activate  # En Windows: venv\Scripts\activate
   ```

3. Install the dependencies:
   ```bash
   pip install -r requirements.txt
   ```

4. Configure environment variables:
   - Make sure the `.env` file includes the following paths:
     ```plaintext
     DATA_PATH=data/raw/
     OUTPUT_PATH=output/
     ```
   - These paths define where the input files are located and where the output files will be saved.

## Data Download
The input files required for this analysis are available in the [Amazon Books Reviews Dataset](https://www.kaggle.com/datasets/mohamedbakhet/amazon-books-reviews/data?select=books_data.csv). Download the following files:
- `books_data.csv`
- `books_rating.csv`

Create the necessary folders and move the files to the specified location:
```bash
mkdir -p data/raw/
mv books_data.csv data/raw/
mv books_rating.csv data/raw/
```

## Running the Project
1. Once the data and dependencies are set up, run the `main.py` file to execute the entire analysis pipeline:
   ```bash
   python main.py
   ```
2. This will generate:
  - **Interactive visualizations** of the processed data.
  - **Excel files** containing lists of the top books, saved in the folder defined by `OUTPUT_PATH`.

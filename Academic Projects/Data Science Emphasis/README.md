# Integrative Project – Life Expectancy Prediction

## Project summary

This project aims to design and implement a predictive model to estimate a country’s life expectancy from socioeconomic, health, and demographic variables. Developed within the Data Science emphasis at Universidad EAFIT, it uses official data from the WHO and UNESCO covering 183 countries from 2000–2016. Following the CRISP-DM methodology, the project seeks to identify the most influential factors affecting longevity and provide evidence-based insights to inform public health policies, combining advanced exploratory analysis, feature selection, and predictive modeling to achieve minimal prediction error.

## Dataset

The dataset used can be accessed through the following link: https://www.kaggle.com/datasets/mmattson/who-national-life-expectancy/data

## Context

This project integrates the knowledge learned in the following subjects:
* Modeling and Simulation
* Applied Machine Learning
* Fundamentals of Data Science
* Algebra in Data Science
* Statistics in Data Science
* Information Storage and Retrieval

And it's the capstone project for the Data Science Emphasis of Universidad EAFIT.

---

## Business Question:
What are the most influential factors affecting a country’s life expectancy—considering health, immunization, economic, and human development variables—and how can these factors be leveraged for prediction?

## Main Objective:
To develop a machine learning model using WHO and UNESCO data from 2000–2016 to predict a country’s life expectancy based on health, immunization, economic, and human development indicators, achieving the lowest possible MAE on the test set to support evidence-based decision-making in public health policies and government strategies.

---

## Requirements
- Python: Version 3.8 or higher
- Additional dependencies: See the `requirements.txt` file

## Files in this folder

- **`Integrative Project Report.pdf`**: Full project report.
- **`Integrative Project Presentation.pptx`**: Full project presentation.
- **`src/`**: Directory containing the project modules:
  - **`Integrative_Project.ipynb`**: Notebook.
  - **`Local_Deployment.ipynb`**: Deployment with tkinter.
  - **`requirements.txt`**: List of required dependencies.
  - **`who_life_exp.csv`**: Dataset.
  - **`model_scaler.zip/`**:
    - **`final_model.pkl`**: Trained final model.
    - **`scaler.pkl`**: Scaler.
  - **`AWS_Deployment/`**:
    - **`Notebooks/`**:
      - `Data prep.ipynb`
      - `EDA.ipynb`
      - `Train Model.ipynb`
      - `Visualizaciones.ipynb`
    -  **`Reproducibility_Guide.pdf`**: Guide for reproducing the project through the AWS web interface.

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
4. Run cells top-to-bottom.

  * Make sure to have the `who_life_exp.csv` in the root directory.

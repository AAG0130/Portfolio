# VGG16 Transfer Learning — O vs R Image Classification

## Project summary 
This notebook downloads an O-vs-R image dataset, builds transfer-learning pipelines using VGG16 (feature-extraction and fine-tuning), trains models, evaluates them on a test set, and visualizes results (loss/accuracy curves and classification reports). The notebook demonstrates data augmentation, checkpointing, learning-rate scheduling and model inference.

**Important notice:**  
Documentation within this notebook was improved and additional explanatory comments were added to facilitate reproducibility and reading. The **original course assignment design and associated intellectual property belong exclusively to IBM Corporation**. The code logic of the original assignment was kept intact except for minimal corrections necessary to ensure the notebook runs without errors.

---

## Files in this folder
- `Waste_Product_Classifier.ipynb` — Notebook.  
- `requirements.txt` — Python packages required to run the notebook.  

---

## How to run locally

1. Create and activate a Python virtual environment:

`python -m venv venv`
`source venv/bin/activate # macOS / Linux`
`venv\Scripts\activate # Windows`

2. Install dependencies:

`pip install -r requirements.txt`

3. Start Jupyter Notebook:

`jupyter notebook Waste_Product_Classifier.ipynb`

4. Run cells top-to-bottom.

## Notes & reproducibility

- The notebook downloads ~ZIP data — ensure network access or replace with a local dataset.    
- Adjust `steps_per_epoch`, `epochs`, and `batch_size` to fit your computational resources.

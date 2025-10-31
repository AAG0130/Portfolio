# Part 1: Concrete Crack Image Classification — Data loading

## Project summary 
This notebook downloads a dataset of concrete crack images, inspects and loads example negative/positive images and prepares lists with file paths for downstream processing. It demonstrates image I/O with PIL/Matplotlib and basic filesystem manipulations for dataset exploration.

**Important notice:**  
Documentation within this notebook was improved and additional explanatory comments were added to facilitate reproducibility and reading. The **original course assignment design and associated intellectual property belong exclusively to IBM Corporation**. The code logic of the original assignment was kept intact except for minimal corrections necessary to ensure the notebook runs without errors.

---

## Files in this folder
- `Data_Loading.ipynb` — Notebook.  
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

`jupyter notebook Data_Loading.ipynb`

4. Run cells top-to-bottom. Verify that `Negative/` and `Positive/` directories exist and contain images.

## Notes & reproducibility

- If you plan to load all images into memory, ensure enough RAM; otherwise, use generators or on-disk batching.

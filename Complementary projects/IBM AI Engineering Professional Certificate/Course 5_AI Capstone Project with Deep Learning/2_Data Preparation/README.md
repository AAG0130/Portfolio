# Part 2: Concrete Crack Image Classification — Data preparation

## Project summary   
This notebook extracts the concrete crack image dataset, creates an ImageDataGenerator, reads the first batches, and displays sample images. It demonstrates basic image extraction and preview steps used in image classification pipelines.

**Important notice:**  
Documentation within this notebook was improved and additional explanatory comments were added to facilitate reproducibility and reading. The **original course assignment design and associated intellectual property belong exclusively to IBM Corporation**. The code logic of the original assignment was kept intact except for minimal corrections necessary to ensure the notebook runs without errors.

---

## Files in this folder
- `Data_Preparation.ipynb` — Notebook with data-prep code (original pipeline preserved; docs added).  
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

`jupyter notebook Data_Preparation.ipynb`

4. Run cells top-to-bottom.

* Make sure to have the `concrete_data_week2.zip` in the root directory.
* Verify that `Negative/` and `Positive/` directories exist and contain images.

## Notes & reproducibility

- `flow_from_directory()` expects a directory structure where subfolders represent class names.
- If you plan to load all images into memory, ensure enough RAM; otherwise, use generators or on-disk batching.

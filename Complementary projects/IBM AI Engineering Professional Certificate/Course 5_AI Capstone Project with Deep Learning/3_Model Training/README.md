# Part 3: Concrete Crack Image Classification — Model training

## Project summary 
This notebook performs transfer learning using a ResNet50 backbone (pretrained on ImageNet) to classify concrete crack images. It extracts a zip dataset, creates Keras `ImageDataGenerator` flows for training/validation, builds a model with ResNet50 base + a classification head, trains the model, and saves the trained model.

**Important notice:**  
Documentation within this notebook was improved and additional explanatory comments were added to facilitate reproducibility and reading. The **original course assignment design and associated intellectual property belong exclusively to IBM Corporation**. The code logic of the original assignment was kept intact except for minimal corrections necessary to ensure the notebook runs without errors.

---

## Files in this folder
- ` Model_Training.ipynb` — Notebook.  
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

`jupyter notebook Model_Training.ipynb`

4. Run cells top-to-bottom.

* Make sure to have the `concrete_data_week3.zip` in the root directory.
* Verify that the structure contains `train/` and `valid/` subdirectories, each with a class subfolder (one per class).

## Notes & reproducibility

- If you plan to load all images into memory, ensure enough RAM; otherwise, use generators or on-disk batching.
- `keras` can be the standalone package or `tensorflow.keras`. If you use TensorFlow 2.x, prefer `from tensorflow.keras...` and install `tensorflow`.  
- If the machine has a GPU, ensure the correct TensorFlow/PyTorch GPU build is installed to accelerate training.  
- If dataset sizes are large, adjust `batch_size_training` and `batch_size_validation` to fit memory / GPU capacity.

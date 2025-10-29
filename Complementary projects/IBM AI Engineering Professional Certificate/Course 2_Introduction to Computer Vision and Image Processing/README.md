# Transfer Learning with Convolutional Neural Networks for Image Classification — CV Studio + PyTorch (ResNet18)

## Project summary  
This notebook performs transfer learning using a pretrained ResNet18 to classify images downloaded from CV Studio. It prepares data loaders, freezes pretrained layers, replaces the final fully-connected layer, trains the classifier with a learning-rate scheduler, reports results back to CV Studio, saves the model and runs a few sample predictions.

**Context:**

CV Studio is a fast, easy, and collaborative open source image annotation tool for teams and individuals. In practice, very few people train an entire Convolutional Network from scratch (with random initialization), because it is relatively rare to have a dataset of sufficient size. Instead, it is common to pretrain a ConvNet on a very large dataset in the lab, then use this Network to train your model. We will use the Convolutional Network as a feature generator, only training the output layer.  In general, 100-200 images will give you a good starting point, and it only takes about half an hour.  Usually, the more images you add, the better your results, but it takes longer and the rate of improvement will decrease.

**Important Notices:**

* This notebook was run in the course environment; therefore, reproducibility is limited in a local environment. 
* The CV Studio license was limited; therefore, the implementation in this tool has already expired and cannot be shared in this notebook.
* Documentation within this notebook was improved, and additional explanatory comments were added to facilitate reproducibility and reading. The **original course assignment design and associated intellectual property belong exclusively to IBM Corporation**. The code logic of the original assignment was kept intact except for minimal corrections necessary to ensure the notebook runs without errors.

---

## Files in this folder
- `CNN_Classification_Pytorch.ipynb` — Notebook.  
- `requirements.txt` — Python packages required to run the notebook.
- `Data/` - Folder with the images used for training and testing.
- `Test/` - Folder with the results of the test.

---

## How to run locally

1. Create and activate a Python virtual environment:

`python -m venv venv`
`source venv/bin/activate # macOS / Linux`
`venv\Scripts\activate # Windows`

2. Install dependencies:

`pip install -r requirements.txt`

3. Start Jupyter Notebook:

`jupyter notebook 8_Predictive_Analysis.ipynb`

4. Run cells top-to-bottom. GPU is recommended for training.

5. If following the CV Studio workflow, ensure `skillsnetwork`/`cvstudio` credentials/environment are correctly set up to download/upload models and results.

## Notes & reproducibility
- CV Studio helper `skillsnetwork.cvstudio` and `ibm_boto3` are required to download the dataset and report results. If running offline, replace dataset acquisition with a local Dataset class or local files.
- Training hyperparameters (lr, scheduler, batch_size, epochs) are set near the top; adjust to speed up or improve results.
- Some packages (e.g., `skillsnetwork` / CV Studio helpers) are specific to the course environment; if they are not available via pip in your local environment, download the dataset manually and use a local `Dataset` class to replace `cvstudioClient` calls.

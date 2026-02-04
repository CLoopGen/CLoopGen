import numpy as np
import matplotlib.pyplot as plt
from sklearn.manifold import TSNE
from sklearn.preprocessing import StandardScaler
from sklearn.decomposition import PCA

import umap
import os

dataset_names = ['tsvc', 'polybench', 'npb', 'openblas', 'spec2006', 'openssl', 'cbench', 'ImageMagick',
                  'gsl', 'redis', 'ffmpeg', 'fftw', 'numpy', 'opencv','rodinia',
                  'nevc']
basic_dataset_names = ['tsvc', 'polybench', 'npb', 'openblas', 'spec2006', 'openssl', 'cbench', 'ImageMagick',
                  'gsl', 'redis', 'ffmpeg', 'fftw', 'numpy', 'opencv','rodinia']

source_dir = "features"
target_dir = "result"
colors = {'tsvc': 'limegreen', 'polybench': 'red', 'npb': 'navy', 'openblas': 'gold',
          'spec2006': 'gold', 'openssl': 'gold', 'cbench': 'gold', 'ImageMagick':'gold',
          'gsl': 'gold', 'redis': 'gold', 'ffmpeg': 'gold', 'fftw': 'gold', 'numpy': 'gold', 'opencv':'gold','rodinia':'gold',
          'nevc': 'dodgerblue', 'llm_cbench': 'pink', 'llm_spec2006': 'gold', 'llm_npb': 'orange', 'real programs': 'gold', 'cola':'limegreen'}

def get_umap(dataset_names):
    X_list = []
    labels_list = []

    for name in dataset_names:
        path = os.path.join(source_dir, f"{name}.npy")
        if not os.path.exists(path):
            raise FileNotFoundError(f"File {path} not found!")
        data = np.load(path)[:,1:]  # ignore the first column which is code line number
        X_list.append(data)
        labels_list.append([name]*len(data))

    feature_dims = [x.shape[1] for x in X_list]
    if len(set(feature_dims)) != 1:
        raise ValueError(f"Inconsistent feature dimensions across datasets: {feature_dims}")

    X = np.vstack(X_list) 
    labels = np.concatenate(labels_list) 

    scaler = StandardScaler()
    X_scaled = scaler.fit_transform(X)

    print("Running UMAP on combined dataset...")
    umap_reducer = umap.UMAP(
        n_neighbors=20, 
        min_dist=0.6, 
        n_components=2,
        random_state=42,
        metric='euclidean' 
    )
    X_umap = umap_reducer.fit_transform(X_scaled)

    return X_umap, labels

def save_fig(X_umap, labels, show_dataset_names, figure_name, index):
    plt.figure(figsize=(10, 8))

    new_labels = []
    for label in labels:
        if index == 1 :
            if label == 'tsvc' or label == 'npb' or label == 'polybench':
                new_labels.append(label)
            elif label in show_dataset_names:
                new_labels.append('real programs')
            else:
                new_labels.append(None) 
        if index == 2:
            if label == 'nevc':
                new_labels.append(label)
            elif label == 'cola':
                new_labels.append(label)
            elif label in show_dataset_names:
                new_labels.append('real programs')
            else:
                new_labels.append(None) 

    
    mask = np.array([x is not None for x in new_labels])
    X_umap = X_umap[mask]
    new_labels = [x for x in new_labels if x is not None]

    if index ==1:
        unique_labels = ['real programs','tsvc', 'polybench', 'npb']
    if index ==2:
        unique_labels = ['real programs','nevc',  'cola']

    for name in unique_labels:
        idx = np.array(new_labels) == name
        color = colors.get(name, 'gray') 
        plt.scatter(
            X_umap[idx, 0], X_umap[idx, 1],
            s=10, alpha=0.8, color=color, label=name, edgecolors='none'
        )
    plt.xlim(-20, 30)
    plt.ylim(-20, 30)
    plt.legend(fontsize=15,loc='upper right')
    plt.xlabel('UMAP Dimension 1')
    plt.ylabel('UMAP Dimension 2')
    plt.grid(True, linestyle='--', alpha=0.5)
    plt.tight_layout()
    plt.savefig(f'{target_dir}/{figure_name}.png', dpi=200, bbox_inches='tight')
    # plt.savefig(f'{target_dir}/{figure_name}.pdf', bbox_inches='tight')

def save_fig1(X_umap, labels, show_dataset_names, figure_name):
    plt.figure(figsize=(10, 8))
    for name in show_dataset_names:
        idx = labels == name
        plt.scatter(
            X_umap[idx, 0], X_umap[idx, 1],
            s=10, alpha=0.8, color=colors[name], label=name, edgecolors='none'
        )

    plt.xlim(-20, 30)
    plt.ylim(-20, 30)
    plt.grid(True, linestyle='--', alpha=0.5)
    plt.tight_layout()
    plt.savefig(f'{target_dir}/{figure_name}.png', dpi=200, bbox_inches='tight')
    # plt.savefig(f'{target_dir}/{figure_name}.pdf', bbox_inches='tight')

datasets = basic_dataset_names.copy()
datasets.extend(['nevc'])
datasets.extend(['cola'])
X_umap, labels = get_umap(datasets)
exp2_1 = ['openblas', 'spec2006', 'openssl', 'cbench', 'ImageMagick',
                  'gsl', 'redis', 'ffmpeg', 'fftw', 'numpy', 'opencv','rodinia', 'tsvc', 'polybench', 'npb']
exp2_2 = ['openblas', 'spec2006', 'openssl', 'cbench', 'ImageMagick',
                  'gsl', 'redis', 'ffmpeg', 'fftw', 'numpy', 'opencv','rodinia',
                  'nevc', 'cola']
save_fig(X_umap, labels, exp2_1, 'real_benchmarks',1)
save_fig(X_umap, labels, exp2_2, 'real_systhesis',2)

colors = {'tsvc': 'blue', 'polybench': 'blue', 'npb': 'blue', 'openblas': 'blue',
        'spec2006': 'blue', 'openssl': 'blue', 'cbench': 'blue', 'ImageMagick':'blue',
        'gsl': 'blue', 'redis': 'blue', 'ffmpeg': 'blue', 'fftw': 'blue', 'numpy': 'blue', 'opencv':'blue','rodinia':'blue',
        'enhanced_cbench': 'pink', 'enhanced_spec2006': 'pink', 'enhanced_npb': 'pink', 'enhanced_openblas': 'pink', 'enhanced_tsvc': 'pink',
        'enhanced_polybench': 'pink', 'enhanced_openssl': 'pink', 'enhanced_ImageMagick':'pink', 'enhanced_gsl': 'pink', 'enhanced_redis': 'pink',
        'enhanced_ffmpeg': 'pink', 'enhanced_fftw': 'pink', 'enhanced_numpy': 'pink', 'enhanced_opencv':'pink', 'enhanced_rodinia':'pink'}

for program in basic_dataset_names:
    datasets = basic_dataset_names.copy()
    datasets.append(f'enhanced_{program}')
    X_umap, labels = get_umap(datasets)
    save_fig1(X_umap, labels, [f'enhanced_{program}',program], f'{program}_vs_enhanced_{program}')





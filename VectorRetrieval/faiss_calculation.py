"""
author: Li
describe:Faiss implement for RAG
result:dimension(240,768), search cost 15ms-17ms
date:2024/03/28
"""
import pandas as pd
import time
import faiss
from sentence_transformers import SentenceTransformer

# load model and txt
df = pd.read_csv("processed.txt", sep="#",header=None, names=["sentence"])
model_path = "uer/sbert-base-chinese-nli"
model = SentenceTransformer(model_path)
# word embedding
sentences = df['sentence'].tolist()
sentence_embeddings = model.encode(sentences)

print(sentence_embeddings.shape)
dimension = sentence_embeddings.shape[1]
# create index
index = faiss.IndexFlatL2(dimension)
index.add(sentence_embeddings)


def search_text_embedding(top_k, encoder_model, text, faiss_index):
    search = encoder_model.encode([text])
    D, I = faiss_index.search(search, top_k)
    return I


I = search_text_embedding(5, model, "嘉世战队", index)
print(df['sentence'].iloc[I[0]])
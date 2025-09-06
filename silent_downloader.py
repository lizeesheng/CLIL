import argparse
import requests
import os
from urllib.parse import urlparse

def silent_download(url):
    try:
        parsed_url = urlparse(url)
        filename = os.path.basename(parsed_url.path)
        
        if not filename:
            filename = "downloaded_file"
        save_path = os.path.join(os.getcwd(), filename)
        with requests.get(url, stream=True, timeout=10) as r:
            r.raise_for_status() 
            with open(save_path, 'wb') as f:
                for chunk in r.iter_content(chunk_size=8192):
                    if chunk:  
                        f.write(chunk)
        
    except Exception as e:
        print(f"下载失败: {str(e)}")

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='slient download')
    parser.add_argument('-url', required=True, help='URL')
    args = parser.parse_args()
    silent_download(args.url)
    

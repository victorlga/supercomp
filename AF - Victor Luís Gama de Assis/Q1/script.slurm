#!/bin/bash
#SBATCH --job-name=victor
#SBATCH --nodes=2
#SBATCH --ntasks-per-node=5
#SBATCH --cpus-per-task=1
#SBATCH --partition=prova
#SBATCH --mem-per-cpu=300M      # 300 (mem) * 1 (cpus) * 5 (tasks) * 2 (nodes) = 3000M = 3000 (mem)

export OMP_NUM_THREADS=5        # 5 (threads) * 2 (nodes) = 10 (threads)

./executavel

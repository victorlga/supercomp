#!/bin/bash
#SBATCH --job-name=victor
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=1
#SBATCH --cpus-per-task=1
#SBATCH --partition=espec
#SBATCH --mem=100M

export OMP_NUM_THREADS=1

echo Resultado usando 1 core
./main
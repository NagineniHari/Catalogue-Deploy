apiVersion: argoproj.io/v1alpha1
kind: ApplicationSet
metadata:
  name: catalogue-dev
spec:
  generators:
    - list:
        elements:
          - name: catalogue-dev
            namespace: catalogue
  template:
    metadata:
      name: '{{name}}'
    spec:
      project: default
      source:
        repoURL: https://github.com/org/repo.git
        targetRevision: HEAD
        path: apps/catalogue
      destination:
        server: https://kubernetes.default.svc
        namespace: '{{namespace}}'
      syncPolicy:
        automated:
          prune: true
          selfHeal: true

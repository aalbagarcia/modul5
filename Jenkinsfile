pipeline {
    agent any
    stages {
        stage('documentación') {
            steps {
                sh 'make doc'
            } 
            post {
                always {
                    publishHTML([allowMissing: false, 
                                 alwaysLinkToLastBuild: true, 
                                 keepAll: true, 
                                 reportDir: 'html', 
                                 reportFiles: 'index.html', 
                                 reportName: 'Doxygen Documentación', 
                                 reportTitles: ''])
                }
            }
        }
        stage ('CppCheck') {
            steps {
                sh 'make cppcheck-xml'
            }

            post {
                always {
                    publishCppcheck displayErrorSeverity: true, 
                                    displayNoCategorySeverity: true, 
                                    displayPerformanceSeverity: true, 
                                    displayPortabilitySeverity: true, 
                                    displayStyleSeverity: true, 
                                    displayWarningSeverity: true, 
                                    failureThreshold: '1', 
                                    pattern: 'reports/cppcheck/report.xml', 
                                    severityInformation: false

                }
            }
        }

        stage('Tests') {
            steps {
                sh 'make tests'
            }

            post {
                always {
                    junit 'reports/tests/*.xml'
                }
            }
        }

        stage('Build') {
            steps {
                sh 'make bin'
            }

            post {
                always {
                    recordIssues qualityGates: [[threshold: 1, type: 'TOTAL', unstable: false]], 
                                 tools: [gcc()]
                }
            }
        }
    }
    post {
        always {
            chuckNorris()
        }

        success {
            archiveArtifacts artifacts: 'bin/*', fingerprint: true, onlyIfSuccessful: true
        }
    }
}
